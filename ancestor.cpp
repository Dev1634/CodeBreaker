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

const ll INF = 1e9;
const ll M = 1e9 + 7;
const ll LOG = 18;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
ll pow(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    ll x = pow(a, b/2);
    if (b%2 == 0) return x*x;
    return x*x*a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n; cin >> n;
    vll edges[n];
    ll anc[n][LOG + 5];

    REP(i, n - 1) {
        ll a, b; cin >> a >> b;

        edges[a].pb(b);
        edges[b].pb(a);
    }

    vb vis(n);
    qll q;
    
    q.push(0);
    vis[0] = 1;
    anc[0][0] = -1;

    while (!q.empty()) {
        ll cur = q.fr; q.pop();

        each(x, edges[cur]) {
            if (vis[x]) continue;

            vis[x] = 1;
            anc[x][0] = cur;
            q.push(x);
        }
    }

    FOR(j, 1, LOG + 1, 1) {
        REP(i, n) {
            if (anc[i][j - 1] == -1) anc[i][j] = -1;
            else anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
    }

    ll t; cin >> t;
    while (t--) {
        ll x, k; cin >> x >> k;
        
        RREP(i, LOG + 1) {
            if (k >= (1 << i) && x != -1) {
                x = anc[x][i];
                k -= (1 << i);
            }
        }

        cout << x << '\n';
    }
}
