#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;

    int cnt = 0;
	while (n % 2 == 0) {
		cnt++;
		n /= 2;
	}
    if (cnt) cout << 2 << "^" << cnt << '\n';

	for (int i = 3; i <= sqrt(n); i += 2) {
        int cnt = 0;
		while (n % i == 0) {
			cnt++;
			n /= i;
		}
        if (cnt) cout << i << "^" << cnt << '\n';
	}

	if (n > 2)
		cout << n << "^1\n";
}
