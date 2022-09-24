#include <iostream>
using namespace std;
typedef long long ll;

bool valid(ll m, ll d, ll k) {
    ll res = k, cur = d; d++;

    while (res < m) {
        if (k / cur < 1) return 0;
        res += k / cur;
        cur *= d;
        d++;
    }
    return 1;
}

int main() {
    ll m, d; cin >> m >> d;

    ll l = 0, r = 2;
    while (1) {
        if (valid(m, d, r)) break;
        l = r;
        r *= 2;
    }

    while (l < r) {
        ll mid = (l + r) / 2;
        if (valid(m, d, mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << '\n';
}
