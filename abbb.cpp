#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    
    while(t--) {
        string s; cin >> s;
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'B') {
                if (st.size() == 0) st.push('B');
                else st.pop();
            } else st.push('A');
        }

        cout << st.size() << '\n';
    }
}
