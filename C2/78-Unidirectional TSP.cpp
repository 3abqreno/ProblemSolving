//   _____       _
//  |____ |     | |
//      / / __ _| |__   __ _ _ __ ___ _ __   ___
//      \ \/ _` | '_ \ / _` | '__/ _ \ '_ \ / _ \
//  .___/ / (_| | |_) | (_| | | |  __/ | | | (_) |
//  \____/ \__,_|_.__/ \__, |_|  \___|_| |_|\___/
//                       | |
//                       |_|
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int n,m;
int a[12][102];
int dp[12][102];
int go(int i,int j){
    if(j==m)return 0;
    int &d=dp[i][j];
    if(~d)return d;
    d=min({go(i,j+1),go((i+1)%n,j+1),go((i-1+n)%n,j+1)})+a[i][j];
    return d;
}
void build(int i,int j){
    if(j==m-1)return ;
    int c[]={dp[i][j+1],dp[(i+1)%n][j+1],dp[(i-1+n)%n][j+1]},optimal=dp[i][j]-a[i][j];
    vector<int>best;
    if(c[0]==optimal)best.push_back(i);
    if(c[1]==optimal)best.push_back((i+1)%n);
    if(c[2]==optimal)best.push_back((i-1+n)%n);
    sortv(best);
    cout<<best.front()+1;
    if(j<m-2)cout<<" ";
    build(best.front(),j+1);
}
void solve() {
while(cin>>n>>m){
    for (int i = 0; i < n; ++i)for (int j = 0; j < m; ++j){cin>>a[i][j];dp[i][j]=-1;}
    int ans=1e9,index=0;
    for (int i = 0; i < n; ++i){
        int temp=go(i,0);
        if(temp<ans){
            ans=temp,index=i;
        }
    }
    cout<<index+1;
    if(m>1)cout<<" ";
    build(index,0);
    cout<<'\n'<<ans<<'\n';

}
}

int main() {
    int t = 1;
    //   freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);

    allam
//    cin >> t;
    while (t--) {
        solve();
        if(t)cout << '\n';
    }

}
