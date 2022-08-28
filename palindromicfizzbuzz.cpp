#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll s, e; cin >> s >> e;
    for (ll i = s; i <= e; i++) {
        string s = to_string(i), s1 = s;
        reverse(s1.begin(), s1.end());

        if (s == s1) cout << "Palindrome!\n";
        else cout << i << '\n';
    }
}
