#include <bits/stdc++.h>
using namespace std;
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
#define fastio      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define MOD         1000000007
#define inf         80000000000000
#define ll          long long
#define int         long long
#define vll         vector<ll>
#define pb          push_back
#define all(a)      a.begin(),a.end()
#define fr(i,n)     for(int i=0;i<n;i++)
#define uniq(v)     (v).erase(unique(all(v)),(v).end())
#define ln        cout<<endl;
#define print(v)  fr(i,v.size())cout<<v[i]<<" ";
#define endl        '\n'
#define u_b         upper_bound
#define l_b         lower_bound
#define b_s         binary_search
#define ff          first
#define ss          second
#define vec(v,n)    vll v(n);fr(i,n)cin>>v[i];
#define take(v,n)   fr(i,n)cin>>v[i];

int n, m;
int visited[1001][1001];
char mat[1001][1010];
bool isvalid(int x, int y) {
    return ((x >= 0) && (y >= 0) && (x < n) && (y < m) && (mat[x][y] == '.') );
}
 
void dfs(int i, int j) {
    if ((visited[i][j]))return;
    visited[i][j] = 1;
    if (isvalid(i + 1, j))dfs(i + 1, j);
    if (isvalid(i - 1, j))dfs(i - 1, j);
    if (isvalid(i, j + 1))dfs(i, j + 1);
    if (isvalid(i, j - 1))dfs(i, j - 1);
}
signed  main() {
    cin >> n >> m;
    int res = 0;
    fr(i, n)fr(j, m)cin >> mat[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((mat[i][j] == '.') && visited[i][j] == 0) {
                res++;
                dfs(i, j);
            }
        }
    }
    cout << res << endl;
    return 0;
}
