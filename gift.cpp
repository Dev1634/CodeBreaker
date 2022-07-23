#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n, k; cin >> n >> k;
    int prev; cin >> prev;

    int ans = 0;
    for (int i = 1; i < n; i++) {
        int cur; cin >> cur;

        if (cur + k <= prev) ans++;
        prev = cur;
    }

    cout << ans << '\n';
}
