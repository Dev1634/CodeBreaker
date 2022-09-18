#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

#define fi first
#define se second

int main() {
    ll n, k; cin >> n >> k;
    vector<ll> adj[n + 2];
    bool cats[n + 2], res[n + 2];

    memset(res, 0, sizeof(res));
    for (ll i = 1; i <= n; i++) cin >> cats[i];

    for (ll i = 1; i < n; i++) {
        ll a, b; cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    priority_queue<pll> pq; // (Number of consecutive cats travelled, Node)
    pq.push(pll(-cats[1], 1));
    ll ans = 0;

    while (!pq.empty()) {
        pll cur = pq.top(); pq.pop();
        ll curCats = -cur.fi;
        ll curNode = cur.se;

        if (curCats <= k) res[curNode] = 1;
        if (!res[curNode]) continue;
        
        for (ll i = 0; i < adj[curNode].size(); i++) {
            ll nxNode = adj[curNode][i];
            if (res[nxNode] && adj[curNode].size() == 1) ans++;
            if (res[nxNode]) continue;

            if (cats[nxNode]) pq.push(pll(-curCats - 1, nxNode));
            else pq.push(pll(0, nxNode));
        }
    }

    cout << ans << '\n';
}
