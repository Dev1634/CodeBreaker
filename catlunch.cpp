#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
    ll n, k; cin >> n >> k;
    ll a[n];

    for (ll i = 0; i < n; i++) cin >> a[i];

    ll ind = k, ans = 0, res = 0;
    priority_queue<ll> q;

    for (ll i = 0; i < k; i++) q.push(a[i]);
    while (!q.empty()) {
        ll cur = q.top(); q.pop();
        res += cur;
        ans = max(ans, res);

        if (ind < n) q.push(a[ind++]);
    }

    cout << ans << '\n';
}
