#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int e; cin >> e;
        int *low = lower_bound(a, a + n, e), *high = upper_bound(a, a + n, e);
        cout << "Smaller: " << low - a << ", Greater: " << a + n - high << '\n';
    }
}
