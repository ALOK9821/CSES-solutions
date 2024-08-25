#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
    long long n;
    cin >> n;
    long long x;
    cin >> x;
 
    vector<long long> arr(n, 0);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long sum = 0;
    long long ans = 0;
    map<long long, long long> mapp;
    for (long long i = 0; i < n; i++) {
        sum += arr[i];
 
        if (sum == x) {
            ans++;
        }
        if (mapp.find(sum - x) != mapp.end()) {
            ans += mapp[sum - x];
        }
        mapp[sum]++;
    }
    cout << ans << endl;
    return 0;
}
