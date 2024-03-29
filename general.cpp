#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

vector<int> dsu, pow;

int find(int n) {
    if (dsu[n] == n) return n;
    return dsu[n] = find(dsu[n]);
}

void merge(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) {
        cout << "-1\n";
        return;
    } else if (pow[a] < pow[b]) swap(a, b);

    dsu[b] = a;
    cout << a + 1 << '\n';
}

int main() {
    int n, m; cin >> n >> m;
    dsu.resize(n);
    pow.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> pow[i];
        dsu[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        merge(a, b);
    }
}