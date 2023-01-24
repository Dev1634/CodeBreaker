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

vector<vll> a, prefSum, h, v;
ll n, m;

ll getSum(ll i1, ll j1, ll i2, ll j2) {
    if (i1 > i2) swap(i1, i2);
    if (j1 > j2) swap(j1, j2);

    return prefSum[i2][j2] - prefSum[i1 - 1][j2] - prefSum[i2][j1 - 1] + prefSum[i1 - 1][j1 - 1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    a = h = v = prefSum = vector<vll>(n + 5, vll(m + 5, 0));

    FOR(i, 1, n + 1, 1) {
        FOR(j, 1, m + 1, 1) {
            cin >> a[i][j];
            prefSum[i][j] = prefSum[i - 1][j] + prefSum[i][j - 1] - prefSum[i - 1][j - 1] + a[i][j];
        }
    }

    FOR(i, 1, n + 1, 1) {
        ll sum = 0, tmp[m + 5];

        FOR(j, 1, m + 1, 1) {
            h[i][j] = a[i][j] + max(sum, 0ll);
            sum = h[i][j];
        }

        sum = 0;
        RFOR(j, 1, m + 1, 1) {
            tmp[j] = a[i][j] + max(sum, 0ll);
            sum = tmp[j];
            h[i][j] = max(h[i][j], tmp[j]);
        }
    }

    FOR(j, 1, m + 1, 1) {
        ll sum = 0, tmp[n + 5];

        FOR(i, 1, n + 1, 1) {
            v[i][j] = a[i][j] + max(sum, 0ll);
            sum = v[i][j];
        }

        sum = 0;
        RFOR(i, 1, n + 1, 1) {
            tmp[i] = a[i][j] + max(sum, 0ll);
            sum = tmp[i];
            v[i][j] = max(v[i][j], tmp[i]);
        }
    }

    ll ans = -INF;
    FOR(i, 1, n + 1, 1) {
        FOR(j, 1, m + 1, 1) {
            ans = max(ans, h[i][j] + v[i][j] - a[i][j]);
        }
    }

    cout << ans << '\n';
}
