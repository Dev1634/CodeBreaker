#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;

    string s = "";
    int cur = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        char ch; cin >> ch;

        if (ch == '(') cur++;
        else cur--;

        if (cur == 0) ans++;
        else if (cur < 0) break;
    }

    cout << ans << '\n';
}
