#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;

    n %= 60*24;
    ll hr = n / 60;
    ll min = n % 60;
    if (hr < 10) cout << "0";
    cout << hr;
    if (min < 10) cout << "0";
    cout << min << '\n';
}
