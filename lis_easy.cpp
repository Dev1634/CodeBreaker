#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll n;
vector<ll> v, dist;

void f(ll cur) {
    if (dist[cur] != -1) return;

    ll res = 0;
    for (ll i = cur + 1; i < n; i++) {
        f(i);
        if (v[i] > v[cur]) res = max(res, dist[i]);
    }
    dist[cur] = res + 1;
}

int main() {
    cin >> n;
    v = dist = vector<ll>(n);
    fill(dist.begin(), dist.end(), -1);

    for (ll i = 0; i < n; i++) cin >> v[i];

    for (ll i = 0; i < n; i++) f(i);
    
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans = max(ans, dist[i]);
    }

    cout << ans << endl;
}
