#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        int e; cin >> e;
        while (!v.empty() && v.back() <= e) v.pop_back();
        v.push_back(e);
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << endl;
    }
}
