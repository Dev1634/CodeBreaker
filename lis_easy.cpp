#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n), dist(n, 1);

    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                dist[i] = max(dist[i], dist[j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dist[i]);
    }

    cout << ans << endl;
}
