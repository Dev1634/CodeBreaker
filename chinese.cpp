#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    int a[n], b[n];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int m; cin >> m;

    sort(a, a + n);
    sort(b, b + n, greater<int>());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += max(0, a[i] + b[i] - m);
    }

    cout << ans * 100 << '\n';
}
