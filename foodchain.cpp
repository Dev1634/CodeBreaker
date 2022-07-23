#include <iostream>
using namespace std;
typedef long long ll;

const ll M = 1e9 + 9;

int main() {
    ll ans = 1;
    for (int i = 0; i < 5; i++) {
        ll n; cin >> n;
        n %= M;
        ans = (ans * n) % M;
    }

    cout << ans << '\n';
}
