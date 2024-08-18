#include <bits/stdc++.h>
using namespace std;
#define fastio      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define MOD         1000000007
#define ll          long long
#define vll         vector<ll>
#define pb          push_back
#define loop(i,n)   for(int i=0;i<n;i++)

int dp[1000][1000];
int main() {
    ll w, h;
    cin >> w >> h;
    for (int i = 0; i <= w; i++) {
        for (int j = 0; j <= h; j++) {
            if (i == j)dp[i][j] = 0;
            else {
                dp[i][j] = MOD;
                for (int k = 1; k < i; k++)dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                for (int k = 1; k < j; k++)dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }
    cout << dp[w][h] << endl;
    return 0;
}
