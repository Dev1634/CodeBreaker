#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    
    while(t--) {
        string s; cin >> s;
        int a[s.size() + 1];
        int ans = 0;

        a[s.size()] = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            a[i] = 0;

            if (s[i] == 'A') {
                if (a[i + 1] > 0) a[i] = a[i + 1] - 1;
                else ans++;
            } else a[i] = a[i + 1] + 1;
        }

        if (a[0] % 2 == 1) ans++;

        cout << ans << '\n';
    }
}
