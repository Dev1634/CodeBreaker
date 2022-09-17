#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;

ll r, c, k, ans;

int main() {
    scanf("%lld %lld %lld", &r, &c, &k);
    ll graph[r + 2][c + 2], sum[r + 2][c + 2];

    memset(graph, 0, sizeof(graph));
    memset(sum, 0, sizeof(sum));

    bool all_equal = 1; int x;
    for (ll i = 1; i <= r; i++) {
        for (ll j = 1; j <= c; j++) {
            scanf("%lld", &graph[i][j]);
            
            if (i == 1 && j == 1) x = graph[i][j];
            else if (graph[i][j] != x) all_equal = 0;
        }
    }

    for (ll i = 1; i <= r; i++) {
        for (ll j = 1; j <= c; j++) {
            sum[i][j] = graph[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    
    for (ll i = 1; i <= r; i++) {
        for (ll j = 1; j <= c; j++) {
            ll lf = 0, rg = min(r - i, c - j) + 1;
            while (lf < rg) {
                int mid = (lf + rg) / 2;

                ll cur = sum[i + mid][j + mid] - sum[i - 1][j + mid] - sum[i + mid][j - 1] + sum[i - 1][j - 1];
                if (cur < k) lf = mid + 1;
                else rg = mid;
            }

            ans += min(r - i, c - j) - lf + 1;
        }
    }

    printf("%lld\n", ans);
}
