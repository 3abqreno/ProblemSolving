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

#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};


void solve() {
    int n,p;
    cin>>n>>p;
    vector<pair<int,int>>v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i].first>>v[i].second;
    }
    long double ans=0;
    for (int i = 1; i < n; ++i) {
    long double c1= v[i].second/p-(v[i].first-1)/p,c2=v[i-1].second/p-(v[i-1].first-1)/p,r1=v[i].second-v[i].first+1,r2=v[i-1].second-v[i-1].first+1;
    ans+= (c1*r2+c2*r1-c1*c2)*2000/(r1*r2);
    }
    long double c1= v[n-1].second/p-(v[n-1].first-1)/p,c2=v[0].second/p-(v[0].first-1)/p,r1=v[n-1].second-v[n-1].first+1,r2=v[0].second-v[0].first+1;
    ans+= (c1*r2+c2*r1-c1*c2)*2000/(r1*r2);
    cout<<fixed<<setprecision(10)<<ans;
}


int main() {
    int t = 1;
    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
    }

}
