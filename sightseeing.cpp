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

#define ll long long 

typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef map<ll, ll> mll;
typedef set<ll> sll;
typedef queue<ll> qll;
typedef queue<pll> qpll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define fr front()
#define bk back()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define FOR(i, a, b, inc) for (ll i = a; i < b; i += inc)
#define RFOR(i, a, b, inc) for (ll i = b - 1; i >= a; i -= inc)
#define REP(i, a) FOR(i, 0, a, 1)
#define RREP(i, a) RFOR(i, 0, a, 1)
#define each(a, x) for (auto& a: x)

struct Edge {
    ll weight;
    pll nodes;
    
    bool operator < (Edge &oth) {
        // this < oth 
        return weight > oth.weight;
    }
};

struct Node {
    ll parent, size = 1;
    vll v;
};

const ll INF = 1e18;
const ll M = 1e9 + 7;

vector<Edge> edges;
ll n, e, q;
vector<Node> dsu;
// size, members 
vll ans;
ll cur;

ll find(ll n) {
    if (n == dsu[n].parent) return n;
    return dsu[n].parent = find(dsu[n].parent);
}

void merge(ll a, ll x) {
    a = find(a); ll b = find(x);
    if (a == b) return;
    
    if (dsu[a].size < dsu[b].size) swap(a, b);
    
    
    if (find(b) == find(1)) {
        each(x, dsu[a].v) {
            ans[x] = cur;
        }
    }
    if (find(a) == find(1)) {  
        each(x, dsu[b].v) {
            ans[x] = cur;
        }
    }
    
    dsu[b].parent = a;
    dsu[a].size += dsu[b].size;
    
    each(x, dsu[b].v) {
        dsu[a].v.pb(x);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> e >> q;
    
    dsu.resize(n + 5);
    FOR(i, 1, n + 1, 1) {
        dsu[i].parent = i;
        dsu[i].v.pb(i);
    }
    ans.resize(n + 5);
    
    REP(i, e) {
        ll u, v, w; cin >> u >> v >> w;
        
        edges.pb({w, {u, v}});
    }
    sort(all(edges));
    
    for (Edge edge : edges) {
        ll weight = edge.weight;
        ll a = edge.nodes.fi;
        ll b = edge.nodes.se;
        
        cur = weight;
        
        merge(a, b);
    }
    
    while (q--) {
        ll x; cin >> x;
        cout << ans[x] << '\n';
    }
}
