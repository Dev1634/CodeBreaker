#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;
    vector<ll> v(n), a, b(n);

    for (ll i = 0; i < n; i++) cin >> v[i];
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i]) a.push_back(v[i]);
    }

    sort(a.begin(), a.end(), greater<ll>());

    ll ans = 0, cur = 0, ind = 0;
    for (ll i = 0; i < n; i++) {
        if (b[i]) cur += a[ind++];
        else cur += v[i];
        ans += cur;
    }

    cout << ans << '\n';
}
