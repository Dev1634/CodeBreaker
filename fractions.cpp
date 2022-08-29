#include <algorithm>
#include <iostream>
using namespace std;

typedef unsigned long long ull;
typedef pair<ull, ull> pll;

#define fi first // Numerator
#define se second // Denominator

bool cmp(pll a, pll b) {
    return a.se * b.fi > b.se * a.fi;
}

int main() {
    ull n; cin >> n;
    pll a[n];

    for (ull i = 0; i < n; i++)
        cin >> a[i].fi >> a[i].se;

    stable_sort(a, a + n, cmp);

    for (ull i = 0; i < n; i++)
        cout << a[i].fi << " " << a[i].se << '\n';
}
