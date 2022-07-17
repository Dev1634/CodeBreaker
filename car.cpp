#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define mg first
#define node second

const int INF = INT32_MAX;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, e; cin >> n >> e;

    vector<ii> adj[n];
    set<int> visited[n];
    int mileage[n];

    mileage[0] = 0;
    for (int i = 1; i < n; i++) mileage[i] = INF;

    for (int i = 0; i < e; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;

        adj[u].push_back(ii(w, v));
        adj[v].push_back(ii(w, u));
    }

    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, 0)); // Distance, Current Node
    while(!pq.empty()) {
        ii cur = pq.top(); pq.pop();

        for (int i = 0; i < adj[cur.node].size(); i++) {
            ii nx = adj[cur.node][i];
            int val = max(mileage[cur.node], nx.mg);

            if (mileage[nx.node] > val)
                mileage[nx.node] = val;

            if (visited[nx.node].find(cur.node) != visited[nx.node].end()) continue;
            pq.push(ii(val, nx.node));

            visited[cur.node].insert(nx.node);
            visited[nx.node].insert(cur.node);
        }
    }

    if (mileage[n - 1] == INF) cout << "-1\n";
    else cout << mileage[n - 1] << endl;
}
