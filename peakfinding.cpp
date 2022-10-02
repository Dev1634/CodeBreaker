#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        ans = max(ans, x);
    }
    
    cout << ans << '\n';
}
