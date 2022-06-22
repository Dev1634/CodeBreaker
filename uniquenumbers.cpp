#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

int main() {
    set<string> s;

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string e; cin >> e;
        s.insert(e);
    }
    cout << s.size() << endl;
}
