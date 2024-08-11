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

constexpr int INF = 2e18;
constexpr int MOD = 1e9 + 7;
constexpr int MODD = 998244353 ;
const double eps = 1e-9;
 
template <typename T>
int szi(T &container) { return static_cast<int32_t>(container.size()); }

int n;
vector<int> adj[200005];
int sumdp[200005];
int subtreedp[200005];
int ans[200005];
void dfs(int node, int parent) {
    subtreedp[node] = 1;
    for (auto child : adj[node]) {
        if (child == parent)continue;
        dfs(child, node);
        sumdp[node] += sumdp[child] + subtreedp[child];
        subtreedp[node] += subtreedp[child];
    }
}
void dfs2(int node, int parent) {
    if (node != 1) {
        ans[node] = (ans[parent] - (sumdp[node] + (subtreedp[node])));
        ans[node] += ((n - subtreedp[node]) + (sumdp[node]));
    }
    for (auto child : adj[node]) {
        if (child == parent)continue;
        dfs2(child, node);
    }
}
signed  main() {
    cin >> n;
    fr(i, n - 1) {
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, -1);
    ans[1] = sumdp[1];
    dfs2(1, -1);
    for (int i = 1; i <= n; i++)cout << ans[i] << " ";

    return 0;
}
