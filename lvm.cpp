#include <iostream>
#include <stack>
using namespace std;

typedef pair<string, int> si;
typedef long long ll;

#define fi first
#define se second

int main() {
    int n; cin >> n;
    stack <int> st;
    si com[n];

    for (int i = 0; i < n; i++) {
        cin >> com[i].fi;
        if (com[i].fi == "PUSH" || com[i].fi == "IFZERO") cin >> com[i].se;
        else com[i].se = 0;
    }

    int idx = 0, reg = 0;
    while (idx < n) {
        if (com[idx].fi == "PUSH") st.push(com[idx].se);
        else if (com[idx].fi == "LOAD") st.push(reg);
        else if (com[idx].fi == "STORE") {
            reg = st.top();
            st.pop();
        } else if (com[idx].fi == "PLUS") {
            int res = st.top(); st.pop();
            res += st.top(); st.pop();
            st.push(res);
        } else if (com[idx].fi == "TIMES") {
            int res = st.top(); st.pop();
            res *= st.top(); st.pop();
            st.push(res);
        } else if (com[idx].fi == "IFZERO") {
            if (st.top() == 0) idx = com[idx].se - 1;
            st.pop();
        } else break;
        idx++;
    }

    cout << st.top() << '\n';
}
