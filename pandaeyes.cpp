#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define f first
#define st second

int main() {
    int n; cin >> n;
    ii a[n];

    for (int i = 0; i < n; i++) {
        int s, e; cin >> s >> e;
        a[i] = ii(e, s);
    }

    sort(a, a + n);
    int ans = 1, cur = a[0].f;
    for (int i = 1; i < n; i++) {
        if (a[i].st >= cur) {
            cur = a[i].f;
            ans++;
        }
    }

    cout << ans << '\n';
}
