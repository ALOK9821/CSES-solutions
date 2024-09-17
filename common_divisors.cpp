//@alok__10
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define ll          long long
#define int         long long int
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
#define gtest(t)    int t; cin>>t; for(int dfhs=0;dfhs<t;dfhs++)
constexpr int MOD = 1e9 + 7;
constexpr int MODD = 998244353 ;
const double eps = 1e-9;
 
template <typename T>
int szi(T &container) { return static_cast<int32_t>(container.size()); }
int m[1000005];
signed  main() {
    int n; cin >> n;
    int a[n];
    fr(i, n) {
        cin >> a[i];
        m[a[i]]++;
    }
    int count = 0;
    for (int i = 1e6; i >= 1; i--) {
        count = 0;
        for (int j = i; j <= 1e6; j += i) {
            count += m[j];
            if (count >= 2) break;
        }
        if (count >= 2) {
            cout << i << endl;
            break;
        }
    }
 
 
    return 0;
}
