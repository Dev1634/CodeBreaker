#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();

    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                if (i == 0) dp[i][j] = j;
                else dp[i][j] = i;
                continue;
            }

            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            if (a[i - 1] != b[j - 1]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            else dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
        }
    }

    cout << dp[n][m] << '\n';
}
