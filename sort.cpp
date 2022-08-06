#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;

bool cmp(string a, string b) {
    ll as = a.size(), bs = b.size();

    if (as != bs) return as < bs;

    return a < b;
}

int main() {
    int n; cin >> n;

    string a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n, cmp);
    
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << '\n';
}