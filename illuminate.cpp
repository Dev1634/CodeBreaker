#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n, m; cin >> n >> m;
    string graph[n];

    for (ll i = 0; i < n; i++) {
        cin >> graph[i];
    }

    ll ans = 0, empty = 0;
    for (ll i = 0; i < n; i++) {
        ll cur = 0;
        for (ll j = 0; j < m; j++) {
            if (graph[i][j] == '#') {
                ans += cur * cur;
                cur = 0;
            } else {
                cur++, empty++;
            }
        }

        ans += cur * cur;
    }

    for (ll j = 0; j < m; j++) {
        ll cur = 0;
        for (ll i = 0; i < n; i++) {
            if (graph[i][j] == '#') {
                ans += cur * cur;
                cur = 0;
            } else {
                cur++;
            }
        }

        ans += cur * cur;
    }

    cout << ans - empty << '\n';
}
