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

string grid[1005];
int dis[1005][1005];
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
char cost[8] = {'2', '6', '4', '0', '3', '7','5', '1'};

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)cin >> grid[i];
    int k;cin>>k;
    for (int i = 0; i <k ; ++i) {
        int a,b,c,d;cin>>a>>b>>c>>d;
        a--,b--,c--,d--;
        deque<pair<int,pair<int,int>>>q;
        memset(dis,0x3f,sizeof dis);
        dis[a][b]=0;
        q.push_back({a,{b,0}});
        while(!q.empty()){
            int u=q.front().first,v=q.front().second.first,dii=q.front().second.second;
            q.pop_front();
            if(dii>dis[u][v])continue;
            if(pair{u,v}==pair{c,d})break;
            for (int j = 0; j < 8; ++j) {
                int x=u+dx[j],y=v+dy[j];
                if(x>=0&&x<n&&y>=0&&y<m&&dis[x][y]>(dis[u][v]+(cost[j]!=grid[u][v]))){
                    dis[x][y]=dis[u][v]+(cost[j]!=grid[u][v]);
                    if(cost[j]==grid[u][v])q.push_front({x,{y,dis[x][y]}});
                    else q.push_back({x,{y,dis[x][y]}});
                }
            }

        }
        cout<<dis[c][d]<<'\n';
    }

}

int main() {
    int t = 1;
//       freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);

    allam
//    cin >> t;
    while (t--) {
        solve();
//        cout << '\n';
    }

}
