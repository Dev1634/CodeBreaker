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
const int MOD = 1e9 + 7;
priority_queue<ll> pq;
vll ptAt[(ll)1e6], ans;
ll ptTo[(ll)1e6], n, ht;

int gcd(int a, int b);
int pow(int a, int b);

void func(ll prev) {
    ans[prev] = ht--;
    REP(i, sz(ptAt[prev])) {
        ll cur = ptAt[prev][i];
        ptTo[cur]--;

        if (ptTo[cur] == 0) {
            pq.push(cur);
        }
    }

    if (!pq.empty()) {
        ll cur = pq.top();
        pq.pop();
        func(cur);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    ans.resize(n + 5);

    ht = n;
    ll cur;
    REP(i, n) {
        ll a, b; cin >> a >> b; a--, b--;
        if (a != -2) {
            ptTo[i]++;
            ptAt[a].pb(i);
        }
        if (b != -2) {
            ptTo[i]++;
            ptAt[b].pb(i);
        }

        if (a == -2 && b == -2) cur = i;
    }
    
    func(cur);

    REP(i, n) {
        cout << ans[i] << " ";
    }
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