#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    int x[n], y[n];

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    sort(x, x + n);
    sort(y, y + n);

    if (n % 2 == 0) cout << x[n / 2] << " " << y[n / 2] << '\n';
    else cout << x[(n - 1) / 2] << " " << y[(n - 1) / 2] << '\n';
}
