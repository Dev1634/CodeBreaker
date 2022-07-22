#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define fi first
#define se second

bool cmp(ii a, ii b) {
    int da = a.fi - a.se;
    int db = b.fi - b.se;

    return da > db;
}

int main() {
    int n, a, b; cin >> n >> a >> b;
    
    vector<ii> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].fi;
    }

    for (int i = 0; i < n; i++) cin >> v[i].se;

    sort(v.begin(), v.end(), cmp);

    int ans = 0;
    for (int i = 0; i < a; i++) {
        ans += v[i].fi;
    }

    for (int i = a; i < n; i++) {
        ans += v[i].se;
    }

    cout << ans << '\n';
}
