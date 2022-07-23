#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll findSum(ll n) {
    ll res = 0;
    
    for (ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            res += i;
            if (i != n / i) res += n / i;
        }
    }
    return res - n;
}

int main() {
    ll n; cin >> n;
    ll ans = findSum(n);

    if (findSum(ans) == n && ans != n) cout << ans << '\n';
    else cout << "-1\n";
}
