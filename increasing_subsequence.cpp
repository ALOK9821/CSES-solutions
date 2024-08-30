#include <bits/stdc++.h>
using namespace std;
#define fastio      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define MOD         1000000007
#define ll          long long
#define vll         vector<ll>
#define pb          push_back
#define loop(i,n)   for(int i=0;i<n;i++)
int main() {
    int n; cin >> n;
    vector<int> v(n), res;
    for (int&i : v)cin >> i;
    res.pb(v[0]);
    for (int i = 1; i < n; i++) {
        if (v[i] > res[res.size() - 1])res.pb(v[i]);
        else res[lower_bound(res.begin(), res.end(), v[i]) - res.begin()] = v[i];
    }
    cout << res.size() << endl;
    return 0;
}
