#include <iostream>
using namespace std;
typedef long long ll;

const int INF = 1e9;

int main() {
    int n; cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) cin >> a[i];

    int dp[n];

    dp[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = a[i];
        if (dp[i + 1] < 0) dp[i] += dp[i + 1];
    }

    int ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[i]);
    }

    cout << ans << '\n';
}
