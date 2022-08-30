//   _____       _
//  |____ |     | |
//     / / __ _| |__   __ _ _ __ ___ _ __   ___
//      \ \/ _` | '_ \ / _` | '__/ _ \ '_ \ / _ \
    //  .___/ / (_| | |_) | (_| | | |  __/ | | | (_) |
//  \____/ \__,_|_.__/ \__, |_|  \___|_| |_|\___/
//                       | |
//                       |_|
#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#include <unordered_map>
 
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
#define F first
#define S second
using namespace std;
typedef long long ll;
const double pi = 3.14159265358979323846;
#define MOD 1000000007
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
 
 
long long gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
ll fastpow(ll b, ll e) {
    if (!e) {
        return 1;
    }
    if (e & 1) {
        return b * fastpow(b, e - 1);
    }
    ll x = fastpow(b, e / 2);
    return x * x;
}
 
 
void solve() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sortv(v);
 
    int go;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            if(i==n-1)go=s.size()/2;
            else go=v[i+1]-1;
            for (int j = v[i] - 1; j <go; ++j) {
                swap(s[j], s[s.size() - j - 1]);
            }
        }
 
    }
    cout << s;
 
}
 
 
int main() {
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    // allam
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
 
}
