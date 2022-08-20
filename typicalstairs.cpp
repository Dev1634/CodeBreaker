#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;

const ll M = 1000000007;

int main() {
    ll n, m; cin >> n >> m;
    ll dp[n + 2];

    memset(dp, -1, sizeof(dp));
    for (ll i = 0; i < m; i++) {
        ll e; cin >> e;
        dp[e] = 0;
    }

    dp[0] = 1;
    if (dp[1] != 0) dp[1] = 1;

    for (ll i = 2; i <= n; i++) {
        if (dp[i] == 0) continue;
        dp[i] = (dp[i - 1]%M + dp[i - 2]%M)%M;
    }

    cout << dp[n] << '\n';
}
