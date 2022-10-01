#include <algorithm>
#include <iostream>
using namespace std;
typedef unsigned long long ull;

int main() {
    ull n, q, k; cin >> n >> q >> k;
    ull a[n], ans[n];

    for (ull i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<ull>());

    ans[0] = a[0];
    int ind = 0;
    for (ull i = 1; i < n; i++) {
        ans[i] = ans[i - 1] + a[i];
        if ((i + 1) % (k + 1) == 0) ans[i] += a[ind++];
    }

    for (ull i = 0; i < q; i++) {
        ull e; cin >> e;

        cout << ans[min(n - 1, e - 1)] << '\n';
    }
}
