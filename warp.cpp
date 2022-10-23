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

typedef string str;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef map<ll, ll> mii;
typedef map<ll, ll> mll;
typedef set<ll> si;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define fr front()
#define bk back()
#define pb push_back
#define pf push_front
#define ins insert
#define fi first
#define se second

#define FOR(i, a, b, inc) for (ll i = a; i < b; i += inc)
#define RFOR(i, a, b, inc) for (ll i = b - 1; i >= a; i -= inc)
#define REP(i, a) FOR(i, 0, a, 1)
#define RREP(i, a) RFOR(i, 0, a, 1)
#define each(a, x) for (auto& a: x)

const ll INF = 1e9;
const ll M = 1e9 + 7;

ll gcd(ll a, ll b);
ll pow(ll a, ll b);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    int a[n];

    REP(i, n) cin >> a[i];

    int dp[n], total[30];

    memset(dp, 0, sizeof(dp));
    memset(total, 0, sizeof(total));
    dp[0] = 1;

    REP(i, n) {
        int ind = 0;
        vi v;

        while (a[i]) {
            int x = a[i] % 2;
            if (x) {
                dp[i] += total[ind];
                dp[i] %= M;
                v.pb(ind);
            }
            a[i] /= 2;
            ind++;
        }

        each(x, v) total[x] = (total[x] + dp[i])%M;
    }

    cout << dp[n - 1] << '\n';
}

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