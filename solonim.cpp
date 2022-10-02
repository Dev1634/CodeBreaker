#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ans += x;
    }

    if (ans % 2) cout << "No\n";
    else cout << "Yes\n";
}
