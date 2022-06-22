#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int INF = 1e9;
int mn = INF;

int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> v;

    int frogs[m], mt[k];
    for (int i = 0; i < m; i++) cin >> frogs[i];
    for (int i = 0; i < k; i++) cin >> mt[i];

    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < k; j++) {
            if (mt[j] % frogs[i] == 0) cnt++;
        }
        if (cnt == mn) {
            v.push_back(i + 1);
        } else if (cnt < mn) {
            v.clear();
            v.push_back(i + 1);
            mn = cnt;
        }
    }

    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
    cout << '\n';
}
