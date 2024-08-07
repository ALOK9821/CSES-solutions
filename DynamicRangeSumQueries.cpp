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
#define test(t)     int t; cin>>t; while(t--)
#define inmap(x,mymap) mymap.find(x)!=mymap.end()


ll a[200005], seg[4 * 200005];
void build(ll ind, ll low, ll high) {
    if (low == high) {
        seg[ind] = a[low];
        return;
    }
    ll mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
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
    return left + right;
}
void pointupdate(ll ind, ll low, ll high, ll node, ll val) {
    if (low == high) {
        seg[ind] = val;
    }
    else {
        ll mid = (low + high) / 2;
        if (node <= mid && node >= low)pointupdate(2 * ind + 1, low, mid, node, val);
        else pointupdate(2 * ind + 2, mid + 1, high, node, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
}
int main() {
    ll n; cin >> n;
    ll q; cin >> q;
    fr(i, n)cin >> a[i];
    build(0, 0, n - 1);
 
    while (q--) {
        int x; cin >> x;
        if (x == 2) {
            int l, r; cin >> l >> r;
            l--;
            r--;
            cout << query(0, 0, n - 1, l, r) << endl;
        }
        else {
            int ind, val; cin >> ind >> val; ind--;
            pointupdate(0, 0, n - 1, ind, val);
        }
    }
    return 0;
}
