
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

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
double nCr(double n, double r) {
    int i, res;
    if (r > 0)
        return (n / r) * nCr(n - 1, r - 1);
    else
        return 1;
}
void solve() {
   ll n,t,c;
   cin>>n>>t>>c;
   vector<ll>v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }
    vector<ll>seg;
    int index=-1;
    bool start=0;
    for (int i = 0; i < n; ++i) {
        if(v[i]<=t&&!start){
            start=1;
            seg.push_back(i);
        }
        if(v[i]>t&&start){
            seg[seg.size()-1]=i-seg[seg.size()-1];
            start=0;
        }
    }
    if(v[n-1]<=t&&start){
        seg[seg.size()-1]=n-1-seg[seg.size()-1]+1;
    }
    ll ans=0;
    for(auto i:seg){
        if(i>=c){
          ans+=i-c+1;
        }
    }
    cout<<ans;

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
