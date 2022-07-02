#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;
    ll a[n], b[n], mx[n];

    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n; i++) cin >> b[i];

    mx[n - 1] = b[n - 1];
    for (ll i = n - 2; i >= 0; i--) mx[i] = max(mx[i + 1], b[i]);

    ll cur = 0, ans = 0;
    for (ll i = 0; i < n; i++) {
        cur += a[i];

        if (b[i] == mx[i]) {
            ans += cur * b[i];
            cur = 0;
        }
    }

    cout << ans << '\n';
}
