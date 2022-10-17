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

int dp[4005]={};
void solve() {
    for (int i = 0; i < 4005; ++i) {
        dp[i]=INT_MIN;
    }
int n,a,b,c;
cin>>n>>a>>b>>c;
dp[0]=0;
    for (int i = 1; i <= n; ++i) {
        if(i-a>=0)dp[i]=max(dp[i],dp[i-a]+1);
        if(i-b>=0)dp[i]=max(dp[i],dp[i-b]+1);
        if(i-c>=0)dp[i]=max(dp[i],dp[i-c]+1);
    }
    cout<<dp[n];

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
