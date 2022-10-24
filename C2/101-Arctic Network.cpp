//   _____       _
//  |____ |     | |
//     / / __ _| |__   __ _ _ __ ___ _ __   ___
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
#define MOD 1000000007
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

struct dsu {
    vector<int> rank, parent;
    int forests;

    dsu() {}

    dsu(int n) {
        rank.assign(n, 1);
        parent.assign(n, -1);
        forests = n;
    }

    bool unite(int a, int b) {
        int x = find(a), y = find(b);
        if (find(a) != find(b)) {
            forests--;
            if (x > y)parent[y] = x, rank[x] += rank[y];
            else parent[x] = y, rank[y] += rank[x];
            return 1;
        } else return 0;
    }

    int find(int a) {
        if (parent[a] == -1)return a;
        return parent[a] = find(parent[a]);
    }

};

struct edge {
    int from, to, w;

    edge() {}

    edge(int a, int b, int c) : from(a), to(b), w(c) {}

    bool operator<(const edge &other) const {
        return w > other.w;
    }
};

double Kruskal(vector<edge> edgeList, int n, int m) {
    int cost = 0;
    dsu ds(n);
    vector<edge> edges;
    priority_queue<edge> q;
    for (int i = 0; i < edgeList.size(); i++)q.push(edgeList[i]);
    while (!q.empty()) {
        if (edges.size() == (n - m))break;
        if (ds.unite(q.top().from, q.top().to)) {
            cost += q.top().w;
            edges.push_back(q.top());
        }
        q.pop();
    }
    return sqrtl(edges.back().w);
}


void solve() {
    int n, m;
    cin >> m >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    vector<edge> e;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x1 = v[i].first, y1 = v[i].second;
            int x2 = v[j].first, y2 = v[j].second;
            e.push_back(edge(i, j, (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
        }
    }
    cout<<fixed<<setprecision(2)<<Kruskal(e, n, m)<<'\n';
}

int main() {
    int t = 1;
    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    allam
    cin >> t;
    while (t--) {
        solve();
    }

}
