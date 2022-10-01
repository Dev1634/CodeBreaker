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
    ll n; cin >> n;

    vector<pll> edges[n + 2];
    ll dis[n + 2];
    bool vis[n + 2];

    memset(vis, 0, sizeof(vis));
    for (ll i = 1; i < n; i++) {
        ll u, v, w; cin >> u >> v >> w;
        edges[u].push_back(pll(v, w));
        edges[v].push_back(pll(u, -w));
    }

    dis[1] = 0;
    vis[1] = 1;

    queue<ll> q;
    q.push(1);

    while (!q.empty()) {
        ll cur = q.front(); q.pop();

        for (ll i = 0; i < edges[cur].size(); i++) {
            pll nx = edges[cur][i];

            if (vis[nx.fi]) continue;

            dis[nx.fi] = dis[cur] + nx.se;
            vis[nx.fi] = 1;
            q.push(nx.fi);
        }
    }

    ll t; cin >> t;
    while (t--) {
        ll x, y; cin >> x >> y;
        cout << dis[y] - dis[x] << '\n';
    }
}