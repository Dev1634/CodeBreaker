#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef map<ll, ll> mll;
typedef set<ll> sll;
typedef queue<ll> qll;
typedef queue<pll> qpll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define fr front()
#define bk back()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define FOR(i, a, b, inc) for (ll i = a; i < b; i += inc)
#define RFOR(i, a, b, inc) for (ll i = b - 1; i >= a; i -= inc)
#define REP(i, a) FOR(i, 0, a, 1)
#define RREP(i, a) RFOR(i, 0, a, 1)
#define each(a, x) for (auto& a: x)

struct Node {
    ll val, lazy, l, r, lf, rg;
    Node(): val(0), lazy(0), lf(-1), rg(-1) {}
};

const ll INF = 1e9;
const ll M = 1e9 + 7;
Node segTree[(ll) 2e7];
ll cnt = 2;

void propagate(ll idx) {
    if (segTree[idx].lazy) {
        segTree[idx].val += (segTree[idx].r - segTree[idx].l + 1) * segTree[idx].lazy;
        ll mid = (segTree[idx].l + segTree[idx].r) / 2;
        
        if (segTree[idx].lf == -1) {
            segTree[idx].lf = cnt++;
            segTree[segTree[idx].lf].l = segTree[idx].l;
            segTree[segTree[idx].lf].r = mid;
        }
        
        if (segTree[idx].rg == -1) {
            segTree[idx].rg = cnt++;

            segTree[segTree[idx].rg].l = mid + 1;
            segTree[segTree[idx].rg].r = segTree[idx].r;
        }

        segTree[segTree[idx].lf].lazy += segTree[idx].lazy;
        segTree[segTree[idx].rg].lazy += segTree[idx].lazy;
        segTree[idx].lazy = 0;
    }
}

void update(ll idx, ll x, ll y, ll v) {
    if (segTree[idx].l == x && segTree[idx].r == y) {
        segTree[idx].lazy += v;
        propagate(idx);
        return;
    }

    ll mid = (segTree[idx].l + segTree[idx].r) / 2;

    if (segTree[idx].lf == -1) {
        segTree[idx].lf = cnt++;

        segTree[segTree[idx].lf].l = segTree[idx].l;
        segTree[segTree[idx].lf].r = mid;
    }

    if (segTree[idx].rg == -1) {
        segTree[idx].rg = cnt++;

        segTree[segTree[idx].rg].l = mid + 1;
        segTree[segTree[idx].rg].r = segTree[idx].r;
    }

    if (x > mid) update(segTree[idx].rg, x, y, v);
    else if (y <= mid) update(segTree[idx].lf, x, y, v);
    else {
        update(segTree[idx].lf, x, mid, v);
        update(segTree[idx].rg, mid + 1, y, v);
    }

    propagate(segTree[idx].lf);
    propagate(segTree[idx].rg);
    segTree[idx].val = segTree[segTree[idx].lf].val + segTree[segTree[idx].rg].val;
}

ll query(ll idx, ll x, ll y) {
    propagate(idx);

    if (segTree[idx].l == x && segTree[idx].r == y) return segTree[idx].val;
    
    ll mid = (segTree[idx].l + segTree[idx].r) / 2;
    if (segTree[idx].lf == -1) {
        segTree[idx].lf = cnt++;

        segTree[segTree[idx].lf].l = segTree[idx].l;
        segTree[segTree[idx].lf].r = mid;
    }

    if (segTree[idx].rg == -1) {
        segTree[idx].rg = cnt++;

        segTree[segTree[idx].rg].l = mid + 1;
        segTree[segTree[idx].rg].r = segTree[idx].r;
    }

    propagate(segTree[idx].lf);
    propagate(segTree[idx].rg);

    if (x > mid) return query(segTree[idx].rg, x, y);
    else if (y <= mid) return query(segTree[idx].lf, x, y);
    else return query(segTree[idx].lf, x, mid) + query(segTree[idx].rg, mid + 1, y);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, q; cin >> n >> q;

    segTree[1].l = 1; segTree[1].r = n;//(ll) 1e9;

    while (q--) {
        ll t; cin >> t;
        
        if (t == 1) {
            ll l, r, x; cin >> l >> r >> x;
            update(1, l, r, x);
        } else {
            ll l, r; cin >> l >> r;
            cout << query(1, l, r) << endl;
        }
    }
}
