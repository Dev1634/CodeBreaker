#include <iostream>
using namespace std;
typedef unsigned long long ull;

ull gcd(ull a, ull b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ull n; cin >> n;

    for (ull i = 0; i < n; i++) {
        ull a, b; cin >> a >> b;
        cout << a * b / gcd(a, b) << endl;
    }
}
