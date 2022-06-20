#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int n, a, b; cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        if (i % a != 0 && i % b != 0) cout << i;
        if (i % a == 0) cout << "Fizz";
        if (i % b == 0) cout << "Buzz";
        cout << '\n';
    }
}
