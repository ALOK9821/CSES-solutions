#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define ll          long long
#define int         long long
#define vll         vector<ll>
#define pb          push_back
#define all(a)      a.begin(),a.end()
#define fr(i,n)     for(int i=0;i<n;i++)
#define ln          cout<<endl;
#define print(v)    fr(i,v.size())cout<<v[i]<<" ";
#define endl        '\n'
#define ff          first
#define ss          second
#define vec(v,n)    vll v(n);fr(i,n)cin>>v[i];
#define take(v,n)   fr(i,n)cin>>v[i];
#define test(t)     int t; cin>>t; while(t--)
#define inmap(x,mymap) mymap.find(x)!=mymap.end()
 
constexpr int MOD = 1e9 + 7;
constexpr int MODD = 998244353 ;
const double eps = 1e-9;
 
template <typename T>
int szi(T &container) { return static_cast<int32_t>(container.size()); }
 
// adj list to store tree and parent table(up array)
vector<int> adj[200001];
int up[200001][20];
int level[200005];
// dfs to find levels of each nodes
void dfs(int node, int parent, int lvl = 0) {
    level[node] = lvl;
    for (auto child : adj[node])
        if (child != parent)dfs(child, node, lvl + 1);
}
void binary_lifting(int src, int par) {
    up[src][0] = par;
    for (int i = 1; i < 20; i++) {
        if (up[src][i - 1] != -1)
            up[src][i] = up[up[src][i - 1]][i - 1];
        else up[src][i] = -1;
    }
    for (auto child : adj[src])
        if (child != par)
            binary_lifting(child, src);
}
//lift the current node to k levels above
int Lift_node(int node, int jump_required) {
    for (int i = 19; i >= 0; i--) {
        if (jump_required == 0 || node == -1)break;
        if (jump_required >= (1ll << i)) {
            jump_required -= (1ll << i);
            node = up[node][i];
        }
    }
    return node;
}
// finding LCA
int LCA(int u, int v) {
    if (level[u] < level[v])swap(u, v);
    u = Lift_node(u, level[u] - level[v]);
    if (u == v)return u;
    for (int i = 19; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return Lift_node(u, 1);
}
 
signed  main() {
    int n, q; cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int x; cin >> x;
        int index = i + 2;
        adj[index].pb(x);
        adj[x].pb(index);
    }
    dfs(1, -1);
    binary_lifting(1, -1);
    while (q--) {
        int u, v; cin >> u >> v;
        cout << LCA(u, v) << endl;
    }
    timelap();
    return 0;
}
