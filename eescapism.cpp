#include <iostream>
using namespace std;
typedef unsigned long long ull;

const ull M = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ull n; cin >> n;
    ull ans = 0;
    
    for (ull i = 0; i < n; i++) {
        ull e; cin >> e; e %= M;
        ans = (ans + (e * (e + 1) / 2)%M)%M;
    }

    cout << ans << '\n';
}
