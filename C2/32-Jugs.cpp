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
    int to, from, w;

    edge() {}

    edge(int from, int to, int w) : from(from), to(to), w(w) {}

    bool operator<(const edge &other) const {
        return w > other.w;
    }
};

int dijkstra(vector<vector<edge>> adj, int s, int d = -1) {
    int n = adj.size();
    vector<int> dis(n, 1e9), prev(n, -1);
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
    int a, b, c;
    bool start = 1;
    while (cin >> a >> b >> c) {
        int ta = 0, tb = b;
        if(!start)cout<<'\n';
        start=0;
        while (true) {
            cout << "fill B";
            tb = b;
            if (tb == c)break;
            while (true) {
                cout << "\npour B A";
                int temp = ta;
                ta = min(tb, a);
                tb -= ta - temp;
                if ((tb <= 0 || tb == c))break;
                cout << "\nempty A";
                ta = 0;
            }
            if (tb == c)break;
            cout << '\n';
        }
        cout << "\nsuccess";
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
