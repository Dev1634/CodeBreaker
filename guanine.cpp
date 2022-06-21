#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    string ans = "";
    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        if (s[0] == 'A') {
            char ch; cin >> ch;
            if (s == "ADD_FRONT") ans = ch + ans;
            else ans += ch;
        } else if (s[0] == 'S') {
            int k; cin >> k;
            if (s == "SNIP_BACK") ans = ans.substr(0, k + 1);
            else ans = ans.substr(k + 1, ans.size() - k - 1);
        } else {
            int k; cin >> k;
            cout << ans[k] << '\n';
        }
    }
}