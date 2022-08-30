#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    int dp[n];

    for (int i = 0; i < n; i++) {
        char ch; cin >> ch;
        if (ch == 'M') dp[i] = -2;
        else dp[i] = ch - '0';
    }

    for (int i = 1; i < n; i++)
        dp[i] = max(dp[i], dp[i - 1] + dp[i]);

    cout << max(0, *max_element(dp, dp + n)) << '\n';
}
