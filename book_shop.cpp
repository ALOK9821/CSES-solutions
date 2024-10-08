#include <bits/stdc++.h>
using namespace std;
#define fastio      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define MOD         1000000007
#define ll          long long
#define vll         vector<ll>
#define pb          push_back
#define loop(i,n)   for(int i=0;i<n;i++)
int dp[1007][100007];
int main() {
 
    ll n, k; cin >> n >> k;
    vector<int> v(n), pg(n);
    for (auto &i : v)cin >> i;
    for (auto &i : pg)cin >> i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (v[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], pg[i - 1] + dp[i - 1][j - v[i - 1]]);
            }
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][k] << endl;
 
    return 0;
}
