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
            if (x > y)swap(x, y);
            parent[y] = x, rank[x] += rank[y];
            return 1;
        } else return 0;
    }

    int find(int a) {
        if (parent[a] == -1)return a;
        return parent[a] = find(parent[a]);
    }

};

struct edge {
    int from, to, w, index;

    edge() {}

    edge(int a, int b, int c) : from(a), to(b), w(c) {}

    bool operator<(const edge &other) const {
        return w > other.w;
    }
};

pair<int, vector<edge>> Kruskal(vector<edge> edgeList, int n) {
    int cost = 0;
    dsu ds(n+1);
    vector<edge> edges;
    priority_queue<edge> q;
    for (auto i: edgeList)q.push(i);
    while (!q.empty()) {
        if (ds.unite(q.top().from, q.top().to)) {
            cost += q.top().w;
            edges.push_back(q.top());
        }
        q.pop();
    }
    if (edges.size() != n - 1)return {-1, vector<edge>()};
    else return {cost, edges};
}

void solve(int t) {
    cout<<"Case #"<<t<<" : ";
    int n, m;
    cin >> n >> m;
    vector<edge> v(m);
    for (int i = 0; i < m; ++i) {
        cin >> v[i].from >> v[i].to >> v[i].w;
        v[i].index = i;
    }
    pair<int, vector<edge>> a = Kruskal(v, n);
    if (a.first == -1)cout << "No way\n";
    else {
        int ans = 1e9;
        for (int i = 0; i < n-1; ++i) {
            int p = a.second[i].w;
            v[a.second[i].index].w = 1e9 + 7;
            pair<int, vector<edge>> a2 = Kruskal(v, n);
            v[a.second[i].index].w = p;
            if(a2.first==-1)continue;
            ans=min(a2.first,ans);
        }
        if (ans == 1e9)cout << "No second way\n";
        else cout << ans << '\n';
    }

}

int main() {
    int t = 1;
    //    freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
    allam
    cin >> t;
    for (int i = 1; i <=t; ++i) {
    solve(i);
    }

}
