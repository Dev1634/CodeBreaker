#include <iostream>
using namespace std;
typedef long long ll;

const int M = 998244353;
int n;

int main(){
    cin >> n;
    int arr[n+5];
    arr[0] = 0;
    arr[1] = 1;
    for(int i=0;i<2 && i<n;i++) cout << arr[i] << endl;
    for(int i=2;i<=n;i++) {
        arr[i] = (arr[i-2]%M + arr[i-1]%M)%M;
        cout << arr[i] << endl;
    }
}
