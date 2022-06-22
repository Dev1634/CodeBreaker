#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<int> v(n, 0);

    for (int i = 0; i < n - 1; i++) {
        int e; cin >> e;
        v[e - 1]++;
    }

    for (int i = 0; i < n; i++) cout << v[i] << '\n';
}
