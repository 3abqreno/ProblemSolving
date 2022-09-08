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


long long gcd(ll a, ll b) {
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

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};


void solve() {
    ll n;
    cin>>n;
    vector<ll>v1(n);
    vector<ll>v2(n);
    vector<pair<ll,pair<ll,bool>>>vall(2*n);
    vector<vector<bool>>v(2,vector<bool>(n,0));
    ll j=0;
    for (int i = 0; i < n; ++i) {
        cin>>v1[i]>>v2[i];
        vall[j].first=v1[i];
        vall[j].second.first=i;
        vall[j].second.second=0;
        vall[j+1].second.second=1;
        vall[j+1].second.first=i;
        vall[j+1].first=v2[i];
        j+=2;
    }
    sortv(vall);
    for (int i = 0; i < n; ++i) {
        v[vall[i].second.second][vall[i].second.first]=1;
    }
    for (int r = 0; r < 2; ++r) {
        for (int i = 0; i < n; ++i) {
            if(i<=(n/2-1))cout<<1;
            else
            cout<<v[r][i];
        }
        cout<<endl;
    }

}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", std   out);
    allam
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

}
