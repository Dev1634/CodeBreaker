#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n, m; cin >> n >> m;
    if (!(n % m)) {
        for (int i = 0; i < n; i++) {
            cout << n / m << " ";
        }
        cout << '\n';
    } else {
        for (int i = 0; i < m - 1; i++) cout << "1 ";
        for (int i = 0; i < n - m + 1; i++) cout << n - m + 1 << " ";
        cout << '\n';
    }
}
