#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n, h; cin >> n >> h;
    ll a[n];

    for (ll i = 0; i < n - 1; i++) cin >> a[i];

    ll ans = 0;
    for (ll i = 0; i < n - 1; i++)
        if (a[i] >= h / n * (i + 1)) ans++;

    if (!ans) cout << "Yes\n";
    else
        cout << "No\n" << ans << '\n';
}
