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

    int n; cin >> n;
    int a[n];
    vi v;
    mii m;

    REP(i, n) {
        cin >> a[i];
        m[a[i]] = i;
    }

    int cnt = 0;
    FOR(i, 1, n, 1) {
        int leng = m[i];
        RFOR(j, i - 1, leng, 1) {
            m[a[j]]++;
            swap(a[j], a[j + 1]);
            v.pb(j + 1);
            cnt++;
        }
    }

    cout << cnt << '\n';
    each(x, v) cout << x << '\n';
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int pow(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    int x = pow(a, b/2);
    if (b%2 == 0) return x*x;
    return x*x*a;
}