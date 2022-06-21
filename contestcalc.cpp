#include <iostream>
#include <iomanip>
#include <map>
using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    map<string, int> m;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int e; cin >> e;
        m[s] = e;
    }

    int c, ans = 0; cin >> c;
    for (int i = 0; i < c; i++) {
        string s; cin >> s;
        ans += m[s];
    }
    cout << setprecision(1) << fixed << ans / c << endl;
}
