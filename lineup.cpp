#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define fi first
#define se second

const ll INF = 1e9;

int main() {
    ll n; cin >> n;
    map<ll, ll> m;
    set<ll> s;
    pll a[n];

    for (ll i = 0; i < n; i++) {
        ll u, v; cin >> u >> v;
        a[i] = pll(u, v);
        s.insert(v);
    }
    sort(a, a + n);

    queue<pll> q;
    q.push(pll(a[0].fi, a[0].se));
    m[a[0].se]++;

    ll ans = INF;
    for (ll i = 1; i < n; i++) {
        if (m.size() == s.size())
            ans = min(ans, q.back().fi - q.front().fi);

        q.push(pll(a[i].fi, a[i].se)); m[a[i].se]++;
        while (m[q.front().se] > 1) {
            m[q.front().se]--; q.pop();
        }
    }

    if (m.size() == s.size())
        ans = min(ans, max(1ll, q.back().fi - q.front().fi));

    cout << ans << '\n';
}
