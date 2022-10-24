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
vi segTree;

void update(int idx, int l, int r, int x, int u) {
    if (l == r) {
        segTree[idx] = max(0, segTree[idx] + u);
        return;
    }

    int mid = (l + r) / 2;
    if (x <= mid) update(2 * idx, l, mid, x, u);
    else update(2 * idx + 1, mid + 1, r, x, u);

    segTree[idx] = min(segTree[2 * idx], segTree[2 * idx + 1]);
}

int query(int idx, int l, int r) {
    if (l == r)
        return l;

    int mid = (l + r) / 2;
    if (segTree[2 * idx] == 0)
        return query(2 * idx, l, mid);
    else
        return query(2 * idx + 1, mid + 1, r);
}

int gcd(int a, int b);
int pow(int a, int b);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    segTree.resize(4e6 + 5, 0);

    REP(i, n) {
        int a, b; cin >> a >> b;

        if (b <= 1e6) {
            if (a == 1) update(1, 0, 1e6, b - 1, 1);
            else update(1, 0, 1e6, b - 1, -1);
        }
        
        cout << query(1, 0, 1e6) << '\n';
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