#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <cmath>

#include <unordered_map>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef string str;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef set<int> si;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define fr front()
#define bk back()
#define pb push_back
#define pf push_front
#define ins insert
#define fi first
#define se second

#define FOR(i, a, b, inc) for (int i = a; i < b; i += inc)
#define RFOR(i, a, b, inc) for (int i = b - 1; i >= a; i -= inc)
#define REP(i, a) FOR(i, 0, a, 1)
#define RREP(i, a) RFOR(i, 0, a, 1)
#define each(a, x) for (auto& a: x)

const int INF = 1e9;
const int M = 1e9 + 7;

int gcd(int a, int b);
int pow(int a, int b);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll q; cin >> q;
    vll v;

    ll cur = 1;
    while (1) {
        ll tmp2 = cur;
        while (1) {
            ll tmp3 = cur;
            while (1) {
                ll tmp5 = cur;
                while (1) {
                    v.pb(cur);

                    if (cur > 1e18 / 7) break;
                    cur *= 7;
                }
                cur = tmp5;
                if (cur > 1e18 / 5) break;
                cur *= 5;
            }
            cur = tmp3;
            if (cur > 1e18 / 3) break;
            cur *= 3;
        }
        cur = tmp2;
        if (cur > 1e18 / 2) break;
        cur *= 2;
    }

    sort(all(v));

    while (q--) {
        ll l, r; cin >> l >> r;
        
        cout << upper_bound(all(v), r) - lower_bound(all(v), l) << '\n';
    }
}
