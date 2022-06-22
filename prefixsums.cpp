#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q; cin >> n >> q;
    ll a[n];
    ll pref[n];

    for (ll i = 0; i < n; i++) cin >> a[i];

    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        sum += a[i];
        pref[i] = sum;
    }

    for (ll i = 0; i < q; i++) {
        ll a, b; cin >> a >> b; a--, b--;
        if (a == 0) cout << pref[b] << '\n';
        else cout << pref[b] - pref[a-1] << '\n';
    }
}
