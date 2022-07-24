#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;

    set<int> s;
    int a[n];

    for (int i = 0; i < n; i++) {
        int e; cin >> e;
        s.insert(e);
        a[i] = s.size();
    }

    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        cout << a[x - 1] << " ";
    }
    cout << '\n';
}
