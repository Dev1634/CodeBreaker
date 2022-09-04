#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, misplacedCnt = 0; cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != i + 1) misplacedCnt++;
    }

    int q, ans = 0; cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--, r--;

        if (a[l] == l + 1) misplacedCnt++;
        else if (a[l] == r + 1) misplacedCnt--;

        if (a[r] == r + 1) misplacedCnt++;
        else if (a[r] == l + 1) misplacedCnt--;
        swap(a[l], a[r]);

        if (!misplacedCnt) ans++;
    }

    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
}
