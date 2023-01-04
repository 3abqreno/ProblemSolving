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
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

bool vis[101][101] = {};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> points(n + 1);
    vector<vector<int>> rel(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        rel[x].push_back(y);
    }
    int h = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < rel[i].size(); ++j) {
            int x = i, y = rel[i][j];
            if (x > y)swap(x, y);
            if (!vis[x][y]) {
                points[x].push_back({x, h});
                points[y].push_back({y, h});
                h++;
            }
        }
        if(points[i].size()==0)points[i].push_back({i,h}),h++;
    }
    for (int i = 1; i <= n; ++i) {
        cout<<points[i].size()<<'\n';
        for(auto i:points[i])cout<<i.first<<' '<<i.second<<'\n';
    }

}

int main() {
    int t = 1;
    //    freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
    allam
    //    cin >> t;
    while (t--) {
        solve();
    }

}
