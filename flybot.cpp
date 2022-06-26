#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

const ll M = 1000000007;

int main() {
    ll n, m; cin >> n >> m;
    vector<vector<ll> > graph(n, vector<ll>(m, 0));
    graph[0][0] = 1;

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            char ch; cin >> ch;
            if (ch == 'X') {
                graph[i][j] = -1;
                continue;
            }

            if (i > 0) graph[i][j] = (graph[i][j] + max(0ll, graph[i - 1][j])) % M;
            if (j > 0) graph[i][j] = (graph[i][j] + max(0ll, graph[i][j - 1])) % M;
        }
    }

    cout << graph[n - 1][m - 1] % M << '\n';
}