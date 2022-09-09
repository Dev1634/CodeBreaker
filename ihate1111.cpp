#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

const ll INF = 111111111;
map<ll, bool> m;

bool f(ll n) {
    if (m.count(n)) return m[n];

    for (ll cur = INF; cur > 1; cur /= 10)
        if (n % cur == 0) return m[n] = 1;
 
    for (ll cur = INF; cur > 11; cur /= 10) {
        if (cur > n) continue;

        if (f(n - cur)) return m[n] = 1;
    }

    return m[n] = 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        if (f(n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
