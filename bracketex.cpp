#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

char flip(char ch) {
    if (ch == '(') return ')';
    if (ch == '[') return ']';
    return '}';
}

int main() {
    int n; cin >> n;
    string s; cin >> s;

    vector<char> v;

    for (int i = 0; i < n; i++) {
        if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (!v.empty() && s[i] == v.back()) v.pop_back();
            else {
                cout << "Invalid\n";
                return 0;
            }
        } else v.push_back(flip(s[i]));
    }

    if (v.size() == 0) cout << "Valid\n";
    else cout << "Invalid\n";
}
