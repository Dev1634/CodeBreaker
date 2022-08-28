#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

bool cmp1(string a, string b) {
    if (a.size() == b.size()) return a > b;
    return a.size() > b.size();
}

bool cmp2(string a, string b) {
    return a + b > b + a;
}

int main() {
    int n, k; cin >> n >> k;
    string a[n];

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, cmp1);
    sort(a, a + k, cmp2);

    for (int i = 0; i < k; i++) cout << a[i];

    cout << '\n';
}
