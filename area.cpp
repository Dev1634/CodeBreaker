#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        ans += a * b;
    }

    cout << ans << '\n';
}
