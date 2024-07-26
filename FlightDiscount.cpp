#include <bits/stdc++.h>
using namespace std;
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
#pragma GCC optimize("O1")
#define fastio      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define MOD         1000000007
#define inf         800000000000000000
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
#define test(t)     int t; cin>>t; while(t--)
#define inmap(x,mymap) mymap.find(x)!=mymap.end()
#define gtest(t)    int t; cin>>t; for(int dfhs=0;dfhs<t;dfhs++)
#define gkick       cout << "Case #" << dfhs+1 << ": ";
#define ld long double
//----------------------------------------------------------------------------------------------------------------------------------------
ll exp(ll x, ll y, ll p) {x %= p; ll res = 1; while (y) {if (y % 2) res = (res * x % p) % p; x = (x * x) % p; y /= 2; } return res;}
ll expo(ll x, ll y) { ll res = 1; while (y) {if (y % 2) res = (res * x % MOD) % MOD; x = (x * x) % MOD; y /= 2; } return res;}
ll add(ll a, ll b) {return (a % MOD + b % MOD + MOD) % MOD;}
ll sub(ll a, ll b) {return (a % MOD - b % MOD + MOD) % MOD;}
ll mul(ll a, ll b) {return ((a % MOD) * (b % MOD) + MOD) % MOD;}
ll inv(ll x) {return expo(x, MOD - 2);}
// -------------------------------------
int n, m;
vector<pair<int, int>> oenton[100005], ntoone[100005];
int visited[100005];
int dist1ton[100005], distnto1[100005];
 
signed  main() {
    inputoutput();
 
    int n, m; cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        distnto1[i] = 1e18;
        dist1ton[i] = 1e18;
    }
    fr(i, m) {
        int a, b, cost; cin >> a >> b >> cost;
        oenton[a].push_back({b, cost});
        ntoone[b].push_back({a, cost});
    }
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    dist1ton[1] = 0;
    while (!pq.empty()) {
        int curr = pq.top().second;
        pq.pop();
        if (visited[curr])continue;
        visited[curr] = 1;
        for (auto it : oenton[curr]) {
            int price = it.ss;
            if (dist1ton[curr] + price < dist1ton[it.ff]) {
                dist1ton[it.ff] = price + dist1ton[curr];
                pq.push({ -dist1ton[it.ff], it.ff });
 
            }
        }
    }
    for (int i = 0; i <= n; i++)visited[i] = 0;
    pq.push({0, n});
    distnto1[n] = 0;
    while (pq.size()) {
        int curr = pq.top().second;
        pq.pop();
        if (visited[curr])continue;
        visited[curr] = 1;
        for (auto it : ntoone[curr]) {
            int price = it.ss;
            if (distnto1[curr] + price < distnto1[it.ff]) {
                distnto1[it.ff] = price + distnto1[curr];
                pq.push({ -distnto1[it.ff], it.ff });
            }
        }
    }
 
    int res = dist1ton[n];
    for (int i = 1; i <= n; i++) {
        for (auto tt : oenton[i] ) {
            res = min(res, dist1ton[i] + (tt.ss / 2) + distnto1[tt.ff]);
        }
    }
    cout << res << endl;
 
    timelap();
    return 0;
}
