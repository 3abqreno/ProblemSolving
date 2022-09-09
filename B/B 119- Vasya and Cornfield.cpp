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
    if (a == 0)
        return b;
    return gcd(b, a % b) % MOD;
}
 
long long lcm(int a, int b) {
    if (a == 1 && b == 1) {
        return 1;
    }
    return (a / gcd(a, b)) * b;
}
 
 
ll fastpow(ll b, ll e) {
    ll temp;
    if (!e) {
        return 1;
    }
    if (e & 1) {
        temp = (__int128) b * fastpow(b, e - 1) % MOD;
        return temp;
    }
    ll x = fastpow(b, e / 2) % MOD;
    temp = (__int128) x * x % MOD;
    return temp;
}
 
int dx[8] = {0, 0, 1, -1};
int dy[8] = {1, -1, 0, 0};
 
 
void solve() {
    int d,n;
    vector<pair<int,int>>v(4);
    cin>>n>>d;
    v[1]={0,d};
    v[0]={d,0};
    v[3]={n,n-d};
    v[2]={n-d,n};
    vector<pair<double,double>>s(4);
    for (int i = 0; i < 4; ++i) {
        s[i].first=double(v[i].second-v[(i+1)%4].second)/(v[i].first-v[(i+1)%4].first);
        s[i].second=v[i].second-s[i].first*v[i].first;
    }
    int m,x,y,temp;
    cin>>m;
    vector<int>t(4);
    vector<int>ok={1,-1,-1,1};
    for (int i = 0; i < m; ++i) {
        cin>>x>>y;
        for (int j = 0; j < 4; ++j) {
            temp=y-s[j].first*x-s[j].second;
            if(temp<0||temp==0&&(j==1||j==2)){
                t[j]=-1;
            }
            else{
                t[j]=1;
            }
        }
        if(t==ok){
            cout<<"YES";
        }
        else cout<<"NO";
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
