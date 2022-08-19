#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n, m; cin >> n >> m;
    ll a[n];
    
    for (ll i = 0; i < n; i++) cin >> a[i];

    ll ans = 0, cur = 0, total = 0, ind = 0;
    
    while (ind < n) {
        if (cur) {
            total -= a[ind - cur];
            cur--;
        }

        while (ind < n) {
            if (total + a[ind] <= m) {
                total += a[ind];
                cur++, ind++;
            } else if (!cur) break;
            else {
                ind--;
                break;
            }
        }

        ans = max(ans, cur);
        ind++;
    }

    cout << ans << '\n';
}
