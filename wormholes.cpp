#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> ii;

#define fi first
#define se second

int main() {
    int n, w; cin >> n >> w;
    vector<int> edges[n];
    
    for (int i = 0; i < w; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
    }

    priority_queue<ii> q; // (Time Taken, Node)
    q.push(ii(-0, 0));

    while (!q.empty()) {
        ii cur = q.top(); q.pop();

        int dis = -cur.fi, node = cur.se;
        if (node == n - 1) {
            cout << dis << '\n';
            return 0;
        }

        q.push(ii(-dis - 1, node + 1));
        for (int i = 0; i < edges[node].size(); i++) {
            q.push(ii(-dis - 1, edges[node][i]));
        }
    }
}