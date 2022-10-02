#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n, q; cin >> n >> q;
    ll a[n];

    cin >> a[0];
    for (ll i = 1; i < n; i++) {
        cin >> a[i];
        a[i] = min(a[i - 1], a[i]);
    }

    while (q--) {
        ll x; cin >> x;

        if (x < a[n - 1]) {
            cout << "-1 ";
            continue;
        }

        ll l = 0, r = n - 1;
        while (l < r) {
            ll m = (l + r) / 2;
            if (a[m] > x) l = m + 1;
            else r = m;
        }

        cout << l + 1 << ' ';
    }
}
