#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n, greater<int>());

    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}
