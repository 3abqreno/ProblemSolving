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


struct edge {
    int from, to, w, elv;

    edge() {}

    edge(int from, int to, int w, int e) : from(from), to(to), w(w), elv(e) {}

    bool operator<(const edge &other) const {
        return w > other.w;
    }
};


int dijkstra(vector<vector<edge>> adj, int s, int d = -1) {
    int n = adj.size();
    vector<int> dis(n, 1e9), prev(n, -1);
    dis[s] = 0;
    priority_queue<edge> q;
    int cur = 0;
    edge best = edge(0, 0, 1e7, 0);

    q.push(edge(-1,0,0,-1));
    dis[0] = 0;
    while (!q.empty()) {
        edge e = q.top();
        q.pop();
        if (e.w > dis[e.to])continue;
        prev[e.to] = e.from;
        for (auto i: adj[e.to]) {
            int x = dis[i.from] + i.w + (i.elv == e.elv ||e.elv==-1? 0 : 60);
            if (dis[i.to] > x) {
                dis[i.to] = x;
                q.push(edge(i.from, i.to, x, i.elv));
            }
        }
    }
    return d == -1 ? -1 : dis[d];
}

void solve() {
    int n, k, t = 0;
    while (cin >> n >> k) {
        t++;
        if (t > 1)cout << '\n';
        if (n == 0)return;
        vector<int> p(n);
        vector<vector<edge>> adj(100);
        for (auto &i: p)cin >> i;
        vector<vector<int>> elv(n);
        for (int i = 0; i < n; ++i) {
            string s = "";
            while (s.empty())getline(cin, s);
            stringstream ss;
            ss << s;
            int x;
            while (ss >> x)elv[i].push_back(x);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < elv[i].size(); ++j) {
                for (int l = j + 1; l < elv[i].size(); ++l) {
                    int x = elv[i][j], y = elv[i][l];
                    if (x != y) {
                        adj[x].push_back(edge(x, y, (y - x) * p[i], i));
                        adj[y].push_back(edge(y, x, (y - x) * p[i], i));
                    }
                }
            }
        }
        if (adj[0].size()) {
            int ans = dijkstra(adj, 0, k);
            if (ans == 1e9) {
                cout << "IMPOSSIBLE";
            } else cout << ans;
        }else cout<<"IMPOSSIBLE";
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
