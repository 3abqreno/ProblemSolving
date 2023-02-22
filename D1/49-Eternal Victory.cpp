//   _____       _
//  |____ |     | |
//      / / __ _| |__   __ _ _ __ ___ _ __   ___
//      \ \/ _` | '_ \ / _` | '__/ _ \ '_ \ / _ \
//  .___/ / (_| | |_) | (_| | | |  __/ | | | (_) |
//  \____/ \__,_|_.__/ \__, |_|  \___|_| |_|\___/
//                       | |
//                       |_|
#include <bits/stdc++.h>
using namespace std;
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
typedef long long ll;
bool vis[int(1e5+5)]={};
vector<pair<int,int>>adj[int(1e5+5)];
ll dfs(int u){
    vis[u]=1;
    ll take=0;
    for(auto &[i,w]:adj[u]){
        if(vis[i])continue;
        take=max(dfs(i)+w,take);
    }
    return take;
}

void solve() {
int n,a,b,c;cin>>n;
ll sum=0;
    for (int i = 0; i < n-1; ++i) {
        cin>>a>>b>>c;
        adj[--a].emplace_back(--b,c);
        adj[b].emplace_back(a,c);
        sum+=2*c;
    }
    cout<<sum-dfs(0);
}


int main() {
    int t = 1;
//       freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);

    allam
//    cin >> t;
    while (t--) {
        solve();
//        if (t)cout << '\n';
    }

}
