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
#define vec(v,n)    vll v(n);fr(i,n)cin>>v[i];
#define take(v,n)   fr(i,n)cin>>v[i];

int main() {
    int n;
    cin >> n;
    vector<ll> dp(n + 1, 0); dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (j <= i) {
                dp[i] += dp[i - j] % MOD;
            }
        }
    }
    cout << dp[n] % MOD;
    return 0;
}
