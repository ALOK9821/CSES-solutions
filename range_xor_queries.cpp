#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define fastio      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define MOD         1000000007
#define inf         1000000000000007
#define ll          long long
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
ll a[200005], seg[4 * 200005];
void build(ll ind, ll low, ll high) {
    if (low == high) {
        seg[ind] = a[low];
        return;
    }
    ll mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
}
ll query(ll ind, ll low, ll high, ll l, ll r) {
    if (low >= l && high <= r) {
        return seg[ind];
    }
    if (high < l || low > r) {
        return 0;
    }
    ll mid = (low + high) / 2;
    ll left = query(2 * ind + 1, low, mid, l, r);
    ll right = query(2 * ind + 2, mid + 1, high, l, r);
    return left ^ right;
}
int main() {
    ll n; cin >> n;
    ll q; cin >> q;
    fr(i, n)cin >> a[i];
    build(0, 0, n - 1);
 
    while (q--) {
        ll l, r; cin >> l >> r; l--; r--;
        ll x = query(0, 0, n - 1, 0, r);
        ll b = query(0, 0, n - 1, 0, l);
        ll c = a[l];
        cout << ((x ^ b)^c) << endl;
    }
    return 0;
}
