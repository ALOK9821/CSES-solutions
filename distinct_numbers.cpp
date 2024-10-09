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
    set<int> st;
    while (n--) {
        int x; cin >> x;
        st.insert(x);
    }
    cout << st.size() << endl;
 
    return 0;
}
