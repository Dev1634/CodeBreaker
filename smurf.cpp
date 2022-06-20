#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) cin >> a[i];

    int ind = n - 1;
    while (ind >= 0) {
        cout << a[ind] << ' ';
        ind -= 2;
    }

    ind += 2;
    if (n%2 == 0) ind--;
    else ind++;

    while (ind < n) {
        cout << a[ind] << ' ';
        ind += 2;
    }
}
