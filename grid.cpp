#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;

const int M = 1e9 + 7;

int main() {
    int n, m; cin >> n >> m;
    string graph[n];
    int a[n + 2][m + 2];

    for (int i = 0; i < n; i++) cin >> graph[i];

    memset(a, 0, sizeof(a));
    a[1][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) a[i][j] = 1;
            else if (graph[i - 1][j - 1] == '#') continue;
            else a[i][j] = (a[i - 1][j]%M + a[i][j - 1]%M)%M;
        }
    }
    
    cout << a[n][m] << '\n';
}
