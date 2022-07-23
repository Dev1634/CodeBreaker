#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ll n; cin >> n;
    string s; cin >> s;
    
    ll t = 0;
    for (ll i = 0; i < n; i++) {
        if (s[i] == 'L') t++;
    }

    ll ans = 0, cur = 0;
    for (ll i = 0; i < n; i++) {
        if (s[i] == 'L') cur++;
        else ans += cur * (t - cur);
    }

    cout << ans << '\n';
}
