#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

int main() {
    int n, m; cin >> n >> m;

    vector<int> friends[n + 2];
    bool vis[n + 2];

    int ans = 0;
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if (a == 1) friends[a].push_back(b);
        else if (b == 1) friends[b].push_back(a);
        else {
            friends[a].push_back(b);
            friends[b].push_back(a);
        }
    }

    for (int i = 0; i < friends[1].size(); i++) {
        int f = friends[1][i];
        if (!vis[f]) ans++;
        vis[f] = 1;

        for (int j = 0; j < friends[f].size(); j++) {
            int ff = friends[f][j];
            if (vis[ff]) continue;
            vis[ff] = 1; ans++;
        }
    }

    cout << ans << '\n';
}
