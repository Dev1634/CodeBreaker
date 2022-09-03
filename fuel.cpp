#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, l, t; cin >> n >> l >> t;
    ll a[n];

    for (ll i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    bool flag = 1;
    ll ans = 0, ind = -1, cur = t;

    while (cur < l) {
        while (ind + 1 < n && a[ind + 1] <= cur) flag = 0, ind++;

        if (flag) {
            ans = -1;
            break;
        } else cur = a[ind] + t;
        
        flag = 1, ans++;
    }

    cout << ans << '\n';
}
