#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n, k; cin >> n >> k;

    if (k > n*n - n || (n == 2 && k == 2)) cout << "NO\n";
    else {
        cout << "YES\n";

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cnt >= k) cout << ".";
                else if (i == 0) {
                    if (j == n - 1) cout << ".";
                    else {
                        cout << "#";
                        cnt++;
                    }
                } else if (i == n - 1) {
                    if (j == 0) cout << ".";
                    else {
                        cout << "#";
                        cnt++;
                    }
                } else {
                    if (i == j) cout << ".";
                    else {
                        cout << "#";
                        cnt++;
                    }
                }
            }
            cout << '\n';
        }
    }
}
