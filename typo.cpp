#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    string s, t; cin >> s >> t;
    
    bool flag = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t[i]) continue;

        if (!flag) {
            if (i < s.size() - 1 && s[i] == t[i+1] && t[i] == s[i+1]) flag = 1;
            else {
                cout << "No\n";
                return 0;
            }
            i++;
        } else {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}
