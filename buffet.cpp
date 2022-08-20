#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

int main() {
    ll n, k; cin >> n >> k;
    ll dp[2][n], a[n], b[n];

    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n; i++) cin >> b[i];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = a[0];
    dp[1][0] = b[0];

    for (ll i = 1; i < n; i++) {
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] - k) + a[i];
        dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - k) + b[i];
    }

    cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
}
