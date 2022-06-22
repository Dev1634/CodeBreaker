#include <iostream>
using namespace std;
typedef unsigned long long ull;

int main() {
    ull n; cin >> n;
    ull ans = 0;

    while(n) {
        ans += n&1;
        n >>= 1;
    }

    cout << ans << endl;
}
