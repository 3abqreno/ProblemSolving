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
int dx[8] = {0, 1,};
int dy[8] = {1, 0};

struct edge {
    int to, from, w;

    edge() {}

    edge(int from, int to, int w) : from(from), to(to), w(w) {}

    bool operator<(const edge &other) const {
        return w > other.w;
    }
};

int dijkstra(vector<vector<edge>> &adj, int s, int d = -1) {
    int n = adj.size();
    vector<int> dis(n, 2e9), prev(n, -1);
    dis[s] = 0;
    priority_queue<edge> q;
    q.push(edge(-1, s, 0));
    while (!q.empty()) {
        edge e = q.top();
        q.pop();
        if (e.w > dis[e.to])continue;
        prev[e.to] = e.from;
        for (auto i: adj[e.to]) {
            if (dis[i.to] > dis[i.from] + i.w) {
                dis[i.to] = dis[i.from] + i.w;
                q.push(edge(i.from, i.to, dis[i.from] + i.w));
            }
        }
    }
    return d == -1 ? -1 : dis[d];
}

void solve() {
    int n, m, s, d;
    while (cin >> n >> m) {
        if (!n && !m)return;
        vector<string> v(m);
        for (auto &i: v)cin >> i;
        vector<vector<edge>> adj(n * m + 1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (v[i][j] == 'S') {
                    s = i * n + j;
                }
                if (v[i][j] == 'D') {
                    d = i * n + j;
                }
                if (v[i][j] == 'X')continue;
                for (int k = 0; k < 2; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x < m && x >= 0 && y >= 0 && y < n && v[x][y] != 'X') {
                        if (v[x][y] == 'S' || v[x][y] == 'D') {
                            adj[i * n + j].push_back(edge(i * n + j, x * n + y, 0));
                            adj[x * n + y].push_back(edge(x * n + y, i * n + j, v[i][j] - '0'));
                        }
                        else if(v[i][j]=='S'||v[i][j]=='D'){
                            adj[i * n + j].push_back(edge(i * n + j, x * n + y, v[x][y]-'0'));
                            adj[x * n + y].push_back(edge(x * n + y, i * n + j,0));
                        }
                        else {
                            adj[i * n + j].push_back(edge(i * n + j, x * n + y, v[x][y] - '0'));
                            adj[x * n + y].push_back(edge(x * n + y, i * n + j, v[i][j] - '0'));
                        }

                    }
                }
            }
        }
        cout << dijkstra(adj, s, d) << '\n';
    }

}


int main() {
    int t = 1;
    //   freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }

}
