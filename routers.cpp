#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define fi first
#define se second

bool cmp(pll a, pll b) {
    if (a.fi == b.fi) return a.se > b.se;
    return a.fi < b.fi;
}

int main() {
    ll l, n; cin >> l >> n;
    vector<pll> v;

    for (ll i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        v.push_back(pll(max(0ll, x - y), min(l, x + y)));
    }

    sort(v.begin(), v.end(), cmp);
    if (v[0].fi) {
        cout << "-1\n";
        return 0;
    }

    ll ans = 1, cur = v[0].se, ind = 0;
    while (ind < n && cur < l) {
        int mxPos = 0;
        while (ind + 1 < n && v[ind + 1].fi <= cur) {
            ind++;
            if (v[ind].se > v[mxPos].se) {
                mxPos = ind;
            }
        }

        if (!mxPos) {
            cout << "-1\n";
            return 0;
        }

        cur = v[mxPos].se;
        ans++;
    }

    if (cur < l) {
        cout << -1 << "\n";
        return 0;
    }
    cout << ans << '\n';
}
