#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

int main() {
    int n, m; cin >> n >> m;
    int a[n];
    map<int, bool> b;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int e; cin >> e;
        b[e] = 1;
    }

    reverse(a, a + n);
    for (int i = 0; i < n; i++) {
        if (b[a[i]]) cout << a[i] << " ";
    }
    cout << '\n';
}
