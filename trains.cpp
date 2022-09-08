#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

const ll INF = 1e9;

int main() {
    ll n; cin >> n;
    ll dp[n], a[n];

    for (ll i = 0; i < n; i++) cin >> a[i];

    dp[0] = 1;
    for (ll i = 1; i < n; i++) {
        dp[i] = (i + 1) * (i + 1);
        for (ll j = 0; j < i; j++) {
            if (a[j] < a[i]) continue;
            dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
        }
    }

    ll ans = dp[0] + n * n;
    for (ll i = 1; i < n; i++) {
        ans = min(ans, dp[i] + (n - i) * (n - i));
    }

    cout << ans << '\n';
}
