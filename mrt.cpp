#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

int main() {
    ll n, e, q; cin >> n >> e >> q;

    ll dis[n][n];

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (i == j) dis[i][j] = 0;
            else dis[i][j] = INF;
        }
    }

    for (ll i = 0; i < e; i++) {
        ll a, b, c; cin >> a >> b >> c;
        dis[a][b] = c;
        dis[b][a] = c;
    }

    for (ll k = 0; k < n; k++) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                if (dis[i][k] < INF && dis[k][j] < INF)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
            }
        }
    }

    for (ll i = 0; i < q; i++) {
        ll a, b; cin >> a >> b;
        if (dis[a][b] == INF) cout << "-1\n";
        else cout << dis[a][b] << '\n';
    }
}
