#include<iostream>
#include<vector>
using namespace std;

vector<int> segTree; // Finding Minimum
const int INF = 1e9;
int n, q;

void build(int idx, int l, int r) {
    if (l == r) {
        segTree[idx] = 0;
        return;
    }

    int mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);

    segTree[idx] = min(segTree[2 * idx], segTree[2 * idx + 1]);
}

void update(int idx, int l, int r, int x, int u) {
    if (l == r) {
        segTree[idx] = u;
        return;
    }

    int mid = (l + r) / 2;
    if (x <= mid) update(2 * idx, l, mid, x, u);
    else update(2 * idx + 1, mid + 1, r, x, u);

    segTree[idx] = min(segTree[2 * idx], segTree[2 * idx + 1]);
}

int query(int idx, int l, int r, int x, int y) {
    if (x <= l && r <= y) return segTree[idx];
    if (x > r || l > y) return INF;

    int mid = (l + r) / 2;
    return min(query(2 * idx, l, mid, x, y), query(2 * idx + 1, mid + 1, r, x, y));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    segTree = vector<int>(4 * n);

    build(1, 0, n - 1);

    for (int i = 0; i < q; i++) {
        int x, u, v; cin >> x >> u >> v;
        if (x == 1) update(1, 0, n - 1, u, v);
        else cout << query(1, 0, n - 1, u, v) << '\n';
    }
}
