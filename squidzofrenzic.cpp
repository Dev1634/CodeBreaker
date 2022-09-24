#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> v;
int n, m;

int valid(int x) {
    int res = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > x) return 0;
        
        if (cur + v[i] > x) {
            cur = v[i]; res++;
        } else {
            cur += v[i];
        }
    }

    if (res < m) return 1;
    return 0;
}

int main() {
    cin >> n >> m;

    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int l = 0, r = 2;
    while (1) {
        if (valid(r)) break;
        l = r;
        r *= 2;
    }

    while (l < r) {
        int mid = (l + r) / 2;
        if (valid(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << '\n';
}
