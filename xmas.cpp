#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        int e; cin >> e;
        a[e - 1] = i + 1;
    }

    for (int i = 0; i < n; i++) cout << a[i] << '\n';
}
