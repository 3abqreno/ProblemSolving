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
    
    {\\simpler solution but not mine
     ll a,b;
    cin >> a >> b;

    ll dashaFreq = (lcm(a,b))/a;
    ll mashaFreq = (lcm(a,b))/b;

    a>b?dashaFreq++:mashaFreq++;
    if (dashaFreq>mashaFreq) {
        cout << "Dasha";
    } else if (mashaFreq>dashaFreq) {
        cout << "Masha";
    }else {
        cout << "Equal";
    }


    }
    
    ll a,b,t=0,lc,sa=0,sb=0;
    cin>>a>>b;
    lc=lcm(a,b);
    map<ll,pair<bool,bool>>mp;
    for (ll i = a; i < lc+1; i+=a) {
       mp[i].first=1;
    }
    for (ll i = b; i < lc+1; i+=b) {
        mp[i].second=1;
    }
    for(auto i:mp){
        if(i.second.first&&i.second.second){
            if(a>b)sa+=i.first-t;
            else sb+=i.first-t;
            t=i.first;
        }
        if(i.second.first){
            sa+=i.first-t;
            t=i.first;
        }
        else if(i.second.second){
            sb+=i.first-t;
            t=i.first;
        }
    }
    if(sa==sb)cout<<"Equal";
    else if(sa>sb)cout<<"Dasha";
    else cout<<"Masha";



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
