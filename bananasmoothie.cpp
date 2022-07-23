#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ll n, k; cin >> n >> k;
    vector<ll> v;

    for (ll i = 0; i < n; i++) {
        ll e; cin >> e;
        if (e < 0) continue;

        v.push_back(e);
    }

    sort(v.begin(), v.end(), greater<ll>());

    ll ans = 0;
    for (ll i = k - 1; i < v.size(); i += k) ans += v[i];

    cout << ans << '\n';
}
