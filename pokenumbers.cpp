#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll a, b; cin >> a >> b;

    ll ans = 0;
    for (ll i = 0; i < 9; i++)
        ans += ((a >> i) & 1) << (2 * i + 1);
    
    for (ll i = 0; i < 9; i++)
        ans += ((b >> i) & 1) << (2 * i);

    cout << ans << '\n';
}
