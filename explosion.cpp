#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define fi first
#define se second

bool cmp(pll a, pll b) {
    if (a.fi == b.fi) return a.se < b.se;
    return a.fi < b.fi;
}

int main() {
    ll n, a, b; cin >> n >> a >> b;

    pll dis[n];

    for (ll i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;

        // Manhattan distance
        dis[i] = pll(abs(x - a) + abs(y - b), i + 1);
    }

    sort(dis, dis + n);

    for (ll i = 0; i < n; i++) cout << dis[i].se << " ";
    cout << '\n';
}
