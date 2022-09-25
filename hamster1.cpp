#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n, k; cin >> n >> k;
    int a[n], dp[n];

    for (int i = 0; i < n; i++) cin >> a[i];

    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + abs(a[i] - a[i - 1]);
        for (int j = i - 2; j >= max(0, i - k); j--) {
            dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));
        }
    }

    cout << dp[n - 1] << '\n';
}
