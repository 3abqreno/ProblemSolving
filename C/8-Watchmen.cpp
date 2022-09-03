
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
        return b * fastpow(b, e - 1) % MOD;
    }
    ll x = fastpow(b, e / 2) % MOD;
    return x * x % MOD;
}

double nCr(double n, double r) {
    int i, res;
    if (r > 0)
        return (n / r) * nCr(n - 1, r - 1);
    else
        return 1;
}
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};


void solve() {
   ll n,a,b,sum=0;
   cin>>n;
    map<ll,int>mp;
    map<ll,int>mp_2;
    map<pair<ll,ll>,int>f;
    for (int i = 0; i < n; ++i) {
        cin>>a>>b;
        mp[a]++;
        mp_2[b]++;
        f[{a,b}]++;
    }
    for(auto i:f){
        sum-= (i.second>1?nCr(i.second,2):0);
    }
    for(auto i:mp){
        sum+=(i.second>1? nCr(i.second,2):0);
    }
    for(auto i:mp_2){
        sum+=(i.second>1? nCr(i.second,2):0);
    }
    cout<<sum;
}


int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    allam
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

}
