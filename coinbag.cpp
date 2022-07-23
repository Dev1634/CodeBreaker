#include <algorithm>
#include <iostream>
using namespace std;

typedef pair<int, int> ii;

#define w first
#define v second

int main() {
    int n, m; cin >> n >> m;

    int dp[n + 1][m + 1];
    ii a[n];

    for (int i = 0; i < n; i++) cin >> a[i].w >> a[i].v;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0) dp[i][j] = 0;
            else if (j < a[i - 1].w) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1].w] + a[i - 1].v);
        }
    }

    cout << dp[n][m] << '\n';
}
