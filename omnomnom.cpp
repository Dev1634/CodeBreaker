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
typedef pair<bool, ll> pbll;
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

vector<vll> edges;
vb vis;

pbll f(ll cur) {
    vis[cur] = 1;

    pbll ans = {0, 0};
    each(x, edges[cur]) {
        if (vis[x]) continue;

        pbll p = f(x);

        ans.fi = max(ans.fi, p.fi);
        ans.se += p.se;
    }
    if (ans.fi == 0) {
        ans.fi = 1;
        ans.se++;
    } else if (ans.fi == 1)
        ans.fi = 0;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n; cin >> n;

    edges.resize(n + 5);
    vis.resize(n + 5, 0);

    REP(i, n - 1) {
        ll a, b; cin >> a >> b;

        edges[a].pb(b);
        edges[b].pb(a);
    }

    pbll ans = f(1);
    cout << ans.se << '\n';
}
