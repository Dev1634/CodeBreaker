#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n, k; cin >> n >> k;
    int a[n];
    
    for (int i = 0; i < n; i++) cin >> a[i];

    if (k >= n - 1) {
        cout << "0\n";
        return 0;
    }

    int ans = a[n - k - 1] - a[0];
    for (int i = 1; i <= k; i++) {
        ans = min(ans, a[n - k + i - 1] - a[i]);
    }

    cout << ans << '\n';
}
