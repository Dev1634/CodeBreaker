#include <iostream>
using namespace std;
typedef long long ll;

// Power function
ll pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main() {
    ll t; cin >> t;
    while(t--) {
        ll a, b, m; cin >> a >> b >> m;
        a %= m;
        b %= m;
        cout << pow(a, b)%m << endl;
    }
}
