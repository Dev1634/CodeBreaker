#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ll n, s; cin >> n >> s;
    vector<ll> v;

    ll cur = 0;
    ll sz = n;
    bool flag = 0;
    for (ll i = 0; i < n; i++) {
        ll e; cin >> e;
        if (e == 1) {
            if (!flag) {
                sz -= cur;
                flag = 1;
            } else v.push_back(cur);
            cur = 0;
        } else cur++;
    }
    sz -= cur;
    sort(v.begin(), v.end(), greater<ll>());

    for (ll i = 0; i < v.size(); i++) {
        if (s == 1) break;
        sz -= v[i];
        s--;
    }

    cout << sz << '\n';
}
