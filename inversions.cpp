#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> v;

int ans = 0;

int mergeSort(int l, int r) {
    if (l >= r) return 0;

    int mid = (l + r) / 2;
    int res = mergeSort(l, mid) + mergeSort(mid + 1, r);

    vector<int> tmp;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (v[i] <= v[j]) {
            tmp.push_back(v[i]);
            i++;
        } else {
            tmp.push_back(v[j]);
            j++;
            res += mid - i + 1;
        }
    }
    while (i <= mid) {
        tmp.push_back(v[i]);
        i++;
    }
    while (j <= r) {
        tmp.push_back(v[j]);
        j++;

    }
    for (int i = l; i <= r; i++) {
        v[i] = tmp[i - l];
    }

    return res;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        v.resize(n);

        for (int i = 0; i < n; i++) cin >> v[i];

        cout << mergeSort(0, n - 1) << '\n';

    }
}