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
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;

    int n;
int a[501][501];
int vis[501];
int b[501];
bool bad=0;
vector<int>ans;
void dfs(int u){
    vis[u]=1;
    for (int i = 0; i < n; ++i) {
        if(!a[u][i]||i==u)continue;
        if(!vis[i])dfs(i);
        if(vis[i]==1)return void(bad=1);
        if(bad)return;
    }
    ans.push_back(u);
    vis[u]=2;
}
void solve() {
    memset(a,0,sizeof a);bad=0;ans.clear();
    memset(vis,0,sizeof vis);
    cin>>n;
        for (int i = 0; i < n; ++i) {
         cin>>b[i];
         b[i]--;
            for (int j = 0; j < i; ++j) {
                a[b[j]][b[i]]++;
            }
        }
        int m;cin>>m;
    for (int i = 0; i < m; ++i) {
            int x,y;cin>>x>>y;
            --x,--y;
            swap(a[x][y],a[y][x]);
        }
    for (int i = 0; i < n; ++i) if(!vis[i])dfs(i);
    reverse(all(ans));
   if(bad)return void(cout<<"IMPOSSIBLE");
    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i]+1;
        if(i!=ans.size()-1)cout<<" ";
    }


}

int main() {
    int t = 1;
//       freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);

    allam
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }

}
