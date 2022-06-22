#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n, greater<int>());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i%4 == 3) continue;
        ans += a[i];
    }

    cout << ans << '\n';
}
