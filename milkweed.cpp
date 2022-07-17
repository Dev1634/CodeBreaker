#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

#define fi first
#define se second

vector<vector<int> > graph;
int xinc[] = {0,  0, 1, -1, 1, -1 , 1, -1};
int yinc[] = {1, -1, 0,  0, 1, -1, -1,  1};
int x, y, r, c;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> x >> y >> c >> r; c--;
    r = y - r;

    graph = vector<vector<int> >(y, vector<int>(x, 0));

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            char ch; cin >> ch;
            if (ch == '*') graph[i][j] = -1;
        }
    }

    queue<iii> q;
    q.push(iii(0, ii(r, c))); // Distance, Position

    int ans = 1;
    while(!q.empty()) {
        iii cur = q.front(); q.pop();
        int i = cur.se.fi;
        int j = cur.se.se;

        for (int k = 0; k < 8; k++) {
            int nxI = i + yinc[k];
            int nxJ = j + xinc[k];

            if (nxI < 0 || nxI >= y || nxJ < 0 || nxJ >= x) continue;
            if (graph[nxI][nxJ] != 0) continue;

            graph[nxI][nxJ] = cur.fi + 1;
            q.push(iii(cur.fi + 1, ii(nxI, nxJ)));
            ans = max(ans, cur.fi + 1);
        }
    }

    cout << ans << '\n';
}