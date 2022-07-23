#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

typedef pair<int, int> ii;
typedef pair<bool, ii> bii;

#define fi first
#define se second

int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int ar[a], br[b], cr[c], dr[d];
    map<int, bii> m;

    for (int i = 0; i < a; i++) cin >> ar[i];
    for (int i = 0; i < b; i++) cin >> br[i];
    for (int i = 0; i < c; i++) cin >> cr[i];
    for (int i = 0; i < d; i++) cin >> dr[i];

    for (int ia = 0; ia < a; ia++) {
        for (int ib = 0; ib < b; ib++) {
            int sum = ar[ia] + br[ib];
            m[sum] = bii(1, ii(ar[ia], br[ib]));
        }
    }

    for (int ic = 0; ic < c; ic++) {
        for (int id = 0; id < d; id++) {
            int sum = cr[ic] + dr[id];
            if (m[-sum].fi) {
                cout << m[-sum].se.fi << " " << m[-sum].se.se << " " << cr[ic] << " " << dr[id] << '\n';
                return 0;
            }
        }
    }
}
