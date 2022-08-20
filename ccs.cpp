#include<iostream>
#include<map>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    map<int, int> m;

    for (int i = 0; i < q; i++) {
        string s; cin >> s;
        if (s == "TRANSMIT") {
            int a, b; cin >> a >> b;
            auto itr = m.lower_bound(a);
            if (itr->first > b || itr == m.end()) cout << "YES\n";
            else cout << "NO\n";
        } else if (s == "SLEEP") {
            int e; cin >> e;
            m[e] = 1;
        } else {
            int e; cin >> e;
            m.erase(e);
        }
    }
}
