//   _____       _
//  |____ |     | |
//      / / __ _| |__   __ _ _ __ ___ _ __   ___
//      \ \/ _` | '_ \ / _` | '__/ _ \ '_ \ / _ \
//  .___/ / (_| | |_) | (_| | | |  __/ | | | (_) |
//  \____/ \__,_|_.__/ \__, |_|  \___|_| |_|\___/
//                       | |
//                       |_|
#include <bits/stdc++.h>

#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dp[1005][1005][2];
int cost[1000][2];
int n, m, x, y;
void d(int idx,bool clr,int c){
    if(idx==n)return;
    if(dp[idx][c][2]!=-1)return;
    if(c<x){
        dp[idx][c][clr];
    }
}
void solve() {
    memset(dp,0x3f,sizeof dp);
    cin >> n >> m >> x >> y;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < m; ++i) {
        int cnt=0;
        for (int j = 0; j < n; ++j) {
            if(v[j][i]=='#')cnt++;
        }
        cost[i][0]=cnt;
        cost[i][1]=n-cnt;
    }
    dp[0][1][0]=cost[0][0];
    dp[0][1][1]=cost[0][1];
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j <= y; ++j) {
            for (int k = 0; k < 2; ++k) {
                dp[i][j][k]=min(dp[i-1][j-1][k]+cost[i][k],dp[i][j][k]);
                if(j>=x)dp[i][1][1-k]=min(dp[i][1][1-k],dp[i-1][j][k]+cost[i][1-k]);
            }
        }
    }
    int ans=INT_MAX;
    for (int i = x; i <= y; ++i) {
        ans=min(ans,dp[m-1][i][0]);
        ans=min(ans,dp[m-1][i][1]);
    }
    cout<<ans;

}


int main() {
    int t = 1;
//    freopen("words20K.txt", "r", stdin);//freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
    }

}
