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
vector<vector<ll>> p;
vector<ll> clr;
int n, m, k;
ll dp2[102][102][102];// 100*100 for ranges and * 100 colours
ll go(int idx, int c, int cnt = 0) {
    if(idx==n){
        if(cnt==-1) return 0;
        else return 1e15;
    }
    if(dp2[idx][c][cnt]!=-1)return dp2[idx][c][cnt];
    if(cnt<0)return 1e15;
    if (clr[idx+1] != 0) {
        dp2[idx][c][cnt]=go(idx+1,clr[idx+1],cnt-(c!=clr[idx+1]));
    } else {
        for (int i = 1; i <= m; ++i) {
            ll temp=go(idx+1,i,cnt-((c)!=i));
            if(temp!=-1){
                if(dp2[idx][c][cnt]==-1)dp2[idx][c][cnt]=1e15;
                dp2[idx][c][cnt]=min(temp,dp2[idx][c][cnt]);
            }
        }
    }
    if(dp2[idx][c][cnt]!=-1)
    dp2[idx][c][cnt]+=((clr[idx]==0?p[idx][c-1]:0));
    return dp2[idx][c][cnt];
}

void solve() {
    memset(dp2, -1, sizeof dp2);
    cin >> n >> m >> k;
    clr.resize(n);
    p.resize(n, vector<ll>(m));
    for (auto &i: clr)cin>>i;
    clr.push_back(150);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
           cin>>p[i][j];
        }
    }
    if(clr[0]!=0)dp2[0][clr[0]][k]=go(0,clr[0],k-1);
    else for (int i = 1; i <= m; ++i) {
        dp2[0][i][k]=go(0,i,k-1);
    }
    ll ans=1e15;
    for (int i = 1; i <= m; ++i) {
        if(dp2[0][i][k]!=-1)
        ans=min(dp2[0][i][k],ans);
    }
    cout<<(ans==1e15?-1:ans);
}


int main() {
    int t = 1;
    //   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }

}
