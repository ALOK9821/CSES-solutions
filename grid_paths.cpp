#include <bits/stdc++.h>
using namespace std;
#define fastio      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define MOD         1000000007
#define ll          long long
#define vll         vector<ll>
#define pb          push_back
#define all(a)      a.begin(),a.end()
#define fr(i,n)     for(int i=0;i<n;i++)
#define uniq(v)     (v).erase(unique(all(v)),(v).end())
#define ln        cout<<endl;
#define print(v)  fr(i,v.size())cout<<v[i]<<" ";
#define u_b         upper_bound
#define l_b         lower_bound
#define b_s         binary_search
#define ff          first
#define ss          second

char mat[1005][1005];
ll n;
bool isvalid(ll x, ll y) {
    return (x >= 0 && x < n && y >= 0 && y < n && mat[x][y] == '.');
}
ll dp[1005][1005];
ll solve(ll x, ll y) {
    if (dp[x][y] != -1)return dp[x][y];
    if (x == 0 && y == 0)return 1;
    if (!isvalid(x, y))return 0;
    int res1 = 0, res2 = 0;
    if (isvalid(x - 1, y))res1 = solve(x - 1, y) % MOD;
    if (isvalid(x, y - 1))res2 = solve(x, y - 1) % MOD;
    return (dp[x][y] = res2 + res1);
}
int main() {
    cin >> n;
    fr(i, n)fr(j, n)cin >> mat[i][j];
    memset(dp, -1, sizeof dp);
    if (mat[0][0] == '*')cout << 0;
    else cout << solve(n - 1, n - 1) % MOD;
    return 0;
}
