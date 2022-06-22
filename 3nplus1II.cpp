#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n, m; cin >> n >> m;
    while (--m) {
        if (n == 1) {
            n = -1;
            break;
        }
        if (n%2 == 1) n = n * 3 + 1;
        else n /= 2;
    }
    cout << n << endl;
}
