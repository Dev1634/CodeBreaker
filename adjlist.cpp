#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n, e, a, b;

int main(){
    cin >> n >> e;
    vector<int> arr[n+2];
    for(int i=0;i<e;i++) {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i=1;i<=n;i++) {
        for(int node : arr[i]) {
            cout << node << " ";
        }
        cout << "\n";
    }
}
