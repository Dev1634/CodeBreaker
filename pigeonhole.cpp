#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> segTree;

void update(int idx, int l, int r, int x, int val) {
    if (l == r) {
        segTree[idx] += val;
        return;
    }

    int mid = (l + r) / 2;
    if (x <= mid) update(idx * 2, l, mid, x, val);
    else update(idx * 2 + 1, mid + 1, r, x, val);

    segTree[idx] = max(segTree[idx * 2], segTree[idx * 2 + 1]);
}

int main() {
    int n, h; scanf("%d %d", &n, &h);
    segTree = vector<int>(4 * n, 0);

    for (int i = 0; i < n; i++) {
        int t, x; scanf("%d %d", &t, &x);

        if (t) update(1, 0, n - 1, x % h, 1);
        else update(1, 0, n - 1, x % h, -1);

        printf("%d\n", segTree[1]);
    }
}
