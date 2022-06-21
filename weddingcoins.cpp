#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;

    ll money[] = {1000000, 500000, 100000, 50000, 10000, 5000, 1000, 500, 100, 50, 10, 5, 1};

    int ind = 0;
    ll ans = 0;
    while (n && ind < sizeof(money) / sizeof(ll)) {
        ans += (n - n%money[ind]) / money[ind];
        n %= money[ind++];
    }

    cout << ans << endl;
}
