#include <bits/stdc++.h>
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;
int dx[8] = {0, 0, 1, -1};
int dy[8] = {1, -1, 0, 0};
int n,m;
char grid[501][501];
bool vis[501][501]{};
vector<array<int,3>>ans;
void bfs(int a,int b){
    ans.push_back({'B',a+1,b+1});
    stack<pair<int,int>>s;
    queue<pair<int,int>>q;
    q.push({a,b});
    s.push({a,b});
    vis[a][b]=1;
    while(!q.empty()){
        for (int i = 0; i < 4; ++i) {
            int x=q.front().first+dx[i],y=q.front().second+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m&&!vis[x][y]&&grid[x][y]=='.'){
                q.push({x,y});
                s.push({x,y});
                vis[x][y]=1;
                ans.push_back({'B',x+1,y+1});
            }
        }
        q.pop();
    }
    while(s.size()>1){
        ans.push_back({'D',s.top().first+1,s.top().second+1});
        ans.push_back({'R',s.top().first+1,s.top().second+1});
        s.pop();
    }
}

void solve() {
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <m; ++j)cin>>grid[i][j];
    queue<int>q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(!vis[i][j]&&grid[i][j]=='.'){
                bfs(i,j);
            }
        }
    }
    cout<<ans.size()<<'\n';
    for(auto &i:ans)
        cout<<char(i[0])<<' '<<i[1]<<' '<<i[2]<<'\n';
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    allam

    int _t = 1;
//    cin >> _t;
    while (_t--) {
        solve();
        if(_t)cout << '\n';
    }

}
