#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;
    ll even = 0, odd = 0;

    for (ll i = 0; i < n; i++) {
        ll e; cin >> e;
        if (e % 2 == 0) even++;
        else odd++;
    }
    cout << even * odd << '\n';
}
