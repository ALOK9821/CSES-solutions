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
 
signed  main() {
 
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> dp(n + 5, vector<int> (n + 5, INF));
    fr(i, m) {
        int a, b, c; cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
        dp[b][a] = min(dp[b][a], c);
    }
    fr(i, n + 1)dp[i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    fr(i, q) {
        int a, b; cin >> a >> b;
        cout << ( dp[a][b] == INF ? -1 : dp[a][b]) << endl;
    }
 
    timelap();
    return 0;
}
