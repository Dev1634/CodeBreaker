#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> segTree, v;
const ll INF = 1e18;

void build(ll idx, ll l, ll r) {
    if (l == r) {
        segTree[idx] = v[l];
        return;
    }

    ll mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);

    segTree[idx] = max(segTree[2 * idx], segTree[2 * idx + 1]);
}

void update(ll idx, ll l, ll r, ll x, ll u) {
    if (l == r) {
        segTree[idx] = u;
        return;
    }

    ll mid = (l + r) / 2;
    if (x <= mid) update(2 * idx, l, mid, x, u);
    else update(2 * idx + 1, mid + 1, r, x, u);

    segTree[idx] = max(segTree[2 * idx], segTree[2 * idx + 1]);
}

ll query(ll idx, ll l, ll r, ll x, ll y) {
    if (x <= l && r <= y)
        return segTree[idx];
    if (x > r || y < l)
        return -INF;

    ll mid = (l + r) / 2;
    return max(query(2 * idx, l, mid, x, y), query(2 * idx + 1, mid + 1, r, x, y));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;

    segTree = vector<ll>(4 * n);
    v = vector<ll>(n);

    for (ll i = 0; i < n; i++) cin >> v[i];
    
    build(1, 0, n - 1);
    for (ll i = 0; i < m; i++) {
        ll t, a, b; cin >> t >> a >> b;

        if (t) {
            update(1, 0, n - 1, a, b);
        } else
            cout << query(1, 0, n - 1, a, b) << '\n';
    }
}
