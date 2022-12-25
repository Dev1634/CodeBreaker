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

const ll INF = 1e9;
const ll M = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll q; cin >> q;

    deque<ll> dq1, dq2;

    while (q--) {
        ll t; cin >> t;

        if (t == 1) {
            ll x; cin >> x;

            dq2.pb(x);
            if (sz(dq1) < sz(dq2)) {
                dq1.pb(dq2.fr);
                dq2.pop_front();
            }
        } else {
            dq1.swap(dq2);

            if (sz(dq1) < sz(dq2)) {
                dq1.pb(dq2.fr);
                dq2.pop_front();
            }
        }
    }

    each(x, dq1) cout << x << " ";
    each(x, dq2) cout << x << " ";
    cout << '\n';
}
