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

typedef pair<pll, ll> typ;

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

vll dsu;

ll find(ll x) {
    if (dsu[x] == x) return x;
    return dsu[x] = find(dsu[x]);
}
void merge(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    dsu[x] = y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n; cin >> n;
    typ a[n];
    vector<typ> v;

    REP(i, n) {
        cin >> a[i].fi.fi >> a[i].fi.se;
        a[i].se = i;
    }

    sort(a, a + n, [](typ x, typ y) -> bool {
        return x.fi.fi < y.fi.fi;
    });

    REP(i, n - 1) {
        v.pb({{a[i].se, a[i + 1].se}, abs(a[i + 1].fi.fi - a[i].fi.fi)});
    }

    sort(a, a + n, [](typ x, typ y) -> bool {
        return x.fi.se < y.fi.se;
    });

    REP(i, n - 1) {
        v.pb({{a[i].se, a[i + 1].se}, abs(a[i + 1].fi.se - a[i].fi.se)});
    }

    sort(all(v), [](typ x, typ y) -> bool {
        return x.se < y.se;
    });

    dsu.resize(n);

    REP(i, n) dsu[i] = i;

    ll ans = 0;
    each(edge, v) {
        if (find(edge.fi.fi) != find(edge.fi.se)) {
            merge(edge.fi.fi, edge.fi.se);
            ans += edge.se;
        }
    }

    cout << ans << '\n';
}
