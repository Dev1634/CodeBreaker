#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define fi first
#define se second

int incX[4] = {1, 0, -1, 0};
int incY[4] = {0, 1, 0, -1};
int h, w, x, y, t;

bool valid(int i, int j) {
    return i >= 0 && i < h && j >= 0 && j < w;
}

int main() {
    cin >> h >> w >> x >> y >> t; x--, y--;

    int graph[h][w], ans[h][w];
    bool vis[h][w];
    
    memset(graph, 0, sizeof(graph));
    memset(ans, 0, sizeof(ans));
    memset(vis, 0, sizeof(vis));
    ans[x][y] = 1;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> graph[i][j];

    queue<ii> q;
    q.push(ii(x, y));

    while (!q.empty()) {
        ii cur = q.front(); q.pop();
        vis[cur.fi][cur.se] = 1;

        for (int i = 0; i < 4; i++) {
            ii nx = ii(cur.fi + incX[i], cur.se + incY[i]);
            if (!valid(nx.fi, nx.se)) continue;
            if (vis[nx.fi][nx.se]) continue;
            
            if (abs(graph[nx.fi][nx.se] - graph[x][y]) <= t) {
                vis[nx.fi][nx.se] = ans[nx.fi][nx.se] = 1;
                q.push(nx);
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cout << ans[i][j];
        cout << '\n';
    }
}
