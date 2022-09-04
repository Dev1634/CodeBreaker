#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define fi first
#define se second

bool cmp(ii a, ii b) {
    if (a.se == b.se) return a.fi < b.fi;
    return a.se < b.se;
}

int main() {
    int n, m; cin >> n >> m;
    ii a[n];

    for (int i = 0; i < n; i++) {
        int d, r; cin >> d >> r;

        a[i].fi = max(0, d - r);
        a[i].se = min(m, d + r);
    }

    sort(a, a + n, cmp);
    int ans = 1, cur = a[0].se;

    for (int i = 1; i < n; i++) {
        if (a[i].fi <= cur) continue;

        cur = a[i].se;
        ans++;
    }

    cout << ans << '\n';
}
