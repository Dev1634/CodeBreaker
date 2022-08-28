#include <iostream>
using namespace std;
typedef long long ll;

bool vowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;

    int ans = 2;
    for (int i = 0; i < n; i++) {
        if (!vowel(a[i]) && a[i] != 'n') {
            if (!vowel(a[i + 1])) {
                ans--;
                break;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (!vowel(b[i]) && b[i] != 'n') {
            if (!vowel(b[i + 1])) {
                ans--;
                break;
            }
        }
    }

    if (!ans) cout << "zero\n";
    else if (ans == 1) cout << "wan\n";
    else cout << "su\n";
}
