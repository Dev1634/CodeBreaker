#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll x, y, b; cin >> x >> y >> b;
    ll cur = 1, ans = 0;

    while (cur * b <= x || cur * b <= y) cur *= b;

    while (cur) {
        ll digX = (x - (x % cur)) / cur;
        ll digY = (y - (y % cur)) / cur;

        ans += (digX + digY) % b * cur;
        cur /= b;
    }

    cout << ans << '\n';
}
