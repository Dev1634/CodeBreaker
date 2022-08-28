#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;
    ll a[n], b[n];

    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n, greater<ll>());
    sort(b, b + n);

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans += a[i] * b[i];
    }

    cout << ans << '\n';
}
