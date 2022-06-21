#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;
    for (ll i = 0; i < n; i++) {
        ll e; cin >> e;
        cout << cbrt(e) << endl;
    }
}
