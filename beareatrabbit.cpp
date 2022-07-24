#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;

    ll dp[n][2], a[n];

    for (ll i = 0; i < n; i++) cin >> a[i];

    dp[0][0] = 0;
    dp[0][1] = a[0];
    for (ll i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0] + a[i];
    }

    cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';
}
