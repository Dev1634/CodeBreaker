#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;

    int a[n];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int e; cin >> e;
        ans += e;
    }

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());

    for (int i = 1; i < n; i++) ans += a[i] * i;

    cout << ans << '\n';
}
