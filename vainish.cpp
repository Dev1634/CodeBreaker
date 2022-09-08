#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;
    map<ll, ll> freq;
    vector<ll> v;

    for (ll i = 0; i < n; i++) {
        ll e; cin >> e;
        if (freq[e]++) continue;

        v.push_back(e);
    }
    sort(v.begin(), v.end());

    ll dp[v.size()];
    dp[0] = freq[v[0]] * v[0];
    
    for (ll i = 1; i < v.size(); i++) {
        if (v[i] - v[i - 1] == 1) {
            if (i - 1)
                dp[i] = max(dp[i - 1], dp[i - 2] + freq[v[i]] * v[i]);
            else
                dp[i] = max(dp[i - 1], freq[v[i]] * v[i]);
        }
        else
            dp[i] = dp[i - 1] + freq[v[i]] * v[i];
    }

    cout << dp[v.size() - 1] << '\n';
}
