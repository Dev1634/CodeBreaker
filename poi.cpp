#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

#define fi first
#define se second

bool cmp(iii a, iii b) {
    if (a.fi.fi == b.fi.fi) {
        if (a.fi.se == b.fi.se) {
            return a.se < b.se;
        }
        return a.fi.se > b.fi.se;
    }
    return a.fi.fi > b.fi.fi;
}

int main() {
    int n, t, p; cin >> n >> t >> p; p--;

    int score[t], graph[n][t];

    memset(score, 0, sizeof(score));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < t; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0) score[j]++;
        }
    }

    iii a[n];

    for (int i = 0; i < n; i++) {
        int cur = 0, cnt = 0;
        for (int j = 0; j < t; j++) {
            cur += graph[i][j] * score[j];
            cnt += graph[i][j];
        }

        a[i] = iii(ii(cur, cnt), i);
    }

    sort(a, a + n, cmp);

    for (int i = 0; i < n; i++) {
        if (a[i].se == p) {
            cout << a[i].fi.fi << " " << i + 1 << '\n';
            break;
        }
    }
}