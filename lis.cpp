#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

int main() {
    ll n; cin >> n;
    vector<ll> a(n), dp(n + 2, INF);

    for (ll i = 0; i < n; i++) cin >> a[i];
    dp[0] = -INF;

    for (ll i = 0; i < n; i++) {
        ll j = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if (dp[j - 1] < a[i] && a[i] < dp[j]) {
            dp[j] = a[i];
        }
    }

    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        if (dp[i] < INF) ans = i;
    }

    cout << ans << '\n';
}
