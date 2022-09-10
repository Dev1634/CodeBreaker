#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin >> t;

    while (t--) {
        ll a, p; cin >> a >> p;
        if (a == 1) cout << "1\n";
        else cout << (a + 1) % p << '\n';
    }
}
