#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<vector<char> > graph;
vector<vector<bool> > visited;
int nis[4] = {-1, 1,  0, 0};
int njs[4] = {0,  0, -1, 1};
int n, m;

bool valid(int i, int j) {
    return (0 <= i && i < n) && (0 <= j && j < m) && graph[i][j] == 'H' && !visited[i][j];
}

void dfs(int i, int j) {
    visited[i][j] = 1;

    for (int k = 0; k < 4; k++) {
        if (valid(i+nis[k], j+njs[k])) dfs(i+nis[k], j+njs[k]);
    }
}

int main() {
    cin >> n >> m;
    graph = vector<vector<char> >(n, vector<char>(m));
    visited = vector<vector<bool> >(n, vector<bool>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> graph[i][j];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (valid(i, j)) {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << "Oh, bother. There are " << ans << " pools of hunny.\n";
}
