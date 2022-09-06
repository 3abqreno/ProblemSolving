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

long long lcm(ll a, ll b) {
    if (a == 1 && b == 1) {
        return 1;
    }
    return (a / gcd(a, b)) * b;
}

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};


void solve() {
    string a,b;
    cin>>a>>b;
    map<char,pair<ll,pair<ll,ll>>>mp;
    for (int i = 0; i < a.size(); ++i) {
        mp[a[i]].first++;
    }
    sortv(b);
    for (int i = 0; i < b.size(); ++i) {
        if(mp.find(b[i])!=mp.end()&&(mp[b[i]].first>mp[b[i]].second.first)){
            mp[b[i]].second.first++;
        }
        else if(b[i]!= toupper(b[i])&&mp.find((toupper(b[i])))!=mp.end()){
            mp[toupper(b[i])].second.second++;
        }
        else if(mp.find((tolower(b[i])))!=mp.end()){
            mp[tolower(b[i])].second.second++;
        }
    }
    ll w=0,y=0;
    for(auto i:mp){
        y+=min(i.second.first,i.second.second.first);
        i.second.first-=i.second.second.first;
        if(i.second.first>0)w+=min(i.second.first,i.second.second.second);
    }
    cout<<y<<" "<<w;
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
