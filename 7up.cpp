#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n, k, x; cin >> n >> k >> x;

    int cur = x;
    for (int i = 0; i < k; i++, cur += n) {
        // cout << ">> " << cur << '\n';
        if (cur % 7 == 0) {
            cout << "UP!\n";
            continue;
        }

        bool flag = 1;
        string s = to_string(cur);
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '7') {
                cout << "UP!\n";
                flag = 0;
                break;
            }
        }
        
        if (flag) cout << cur << '\n';
    }
}
