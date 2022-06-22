#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n, m; cin >> n >> m;

    int cur = 0;
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        if (s == "LAND") cur++;
        else if (s == "LEAVE") cur--;
        else cur = 0;
        if (cur > n) {
            cout << "PLAN REJECTED\n";
            return 0;
        }
    }
    cout << "PLAN ACCEPTED\n";
}
