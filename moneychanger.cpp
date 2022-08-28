#include <iostream>
#include <cstring>
using namespace std;

const int INF = 1e9;

int main() {
    int n, v; cin >> n >> v;
    int dp[v + 2], a[n];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i <= v; i++) dp[i] = INF;

    dp[0] = 0;
    for (int i = 0; i <= v; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k <= v / a[j]; k++) {
                if (i + k * a[j] <= v) {
                    dp[i + k * a[j]] = min(dp[i + k * a[j]], dp[i] + k);
                }
            }
        }
    }

    if (dp[v] == INF) cout << "-1\n";
    else cout << dp[v] << '\n';
}
