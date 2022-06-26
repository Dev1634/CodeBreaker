#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;

#define fi first
#define se second

int main() {
    ll n; cin >> n;
    string a[n];
    pair<int, int> ans[n];

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        ans[i].fi = -a[i].size();
        ans[i].se = i;
    }

    stable_sort(ans, ans + n);

    for (ll i = 0; i < n; i++) cout << a[ans[i].se] << endl;
}
