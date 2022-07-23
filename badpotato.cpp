#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            ans = max(ans, cur);
            cur = 0;
        } else cur += a[i];
    }

    cout << max(ans, cur) << endl;
}
