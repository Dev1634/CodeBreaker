#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <ctime>
#include <set>
using namespace std;
typedef long long ll;

// const ll MAX_N = 5e7;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll tc, n, m; cin >> tc;
	pair<ll, ll> a[tc];

	ll i = 0, mxN = 0, mxM = 0;
	while (tc--) {
		ll n, m; cin >> n >> m;
		a[i++] = {n, m};

		mxN = max(mxN, n);
		mxM = max(mxM, m);
	}

	bool isPrime[mxN + 5];
	memset(isPrime, 1, sizeof(isPrime));

	for (ll i = 2; i <= mxN; ++i) {
		if (isPrime[i]) {
			for (ll j = i*i; j <= mxN; j += i) {
				isPrime[j] = 0;
			}
		}
	}

	vector<ll> primes;

	for (ll i = 2; i <= mxN; ++i) {
		if (isPrime[i])
			primes.push_back(i);
	}

	for (auto x : a) {
		ll r = upper_bound(primes.begin(), primes.end(), x.first) - primes.begin();

		if (r < x.second) cout << "-1\n";
		else
			cout << primes[r - x.second] << '\n';
	}
}
