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
vector<vector<int>>adj;
bool black[102];
bool anss[102];
int cur=0,ans=1,n,k;
void back(int u){
if(u==n)   {
    if(ans<cur){
        ans=cur;
        for (int i = 0; i < n; ++i) {
            anss[i]=black[i];
        }
    }
    return;
}
bool ok=1;
if(cur+n-u<ans)return ;
for(auto i:adj[u])if(black[i]){ok=0;break;}
back(u+1);
if(ok){black[u]=1,cur++;back(u+1);black[u]=0,cur--;};
}
void solve() {
    ans=0,cur=0;
    cin>>n>>k;
    for (int i = 0; i < n; ++i)black[i]=anss[i]=0;
adj.assign(n,vector<int>());
    for (int i = 0; i < k; ++i) {
        int a,b;cin>>a>>b;adj[--a].push_back(--b);adj[b].push_back(a);
    }
    back(0);
    cout<<ans<<'\n';
    for (int i = 0; i < n; ++i) {
        if(anss[i]){
            cout<<i+1;
            if(--ans)cout<<" ";
        }
    }

}

int main() {
    int t = 1;
    //   freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);

    allam
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }

}
