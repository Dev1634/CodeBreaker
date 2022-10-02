#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ll n, q; cin >> n >> q;
    vector<ll> v;

    for (ll i = 0; i < q; i++) {
        ll t; cin >> t;

        if (t == 1) {
            ll x; cin >> x;
            v.push_back(x);
        } else {
            v.pop_back();
        }
    }

    if (v.size()) cout << *max_element(v.begin(), v.end()) << '\n';
    else cout << "0\n";
}
