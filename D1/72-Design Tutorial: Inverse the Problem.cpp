#include <bits/stdc++.h>

#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;

struct DSU {
    vector<int> rank, parent;
    int forests;

    DSU() {}

    DSU(int n) {
        rank.assign(n, 1);
        parent.assign(n, -1);
        forests = n;
    }

    bool unite(int a, int b) {
        int x = find(a), y = find(b);
        if (find(a) != find(b)) {
            forests--;
            if (rank[x] < rank[y])swap(x, y);
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
    int from, to, w;

    edge() {}

    edge(int a, int b, int c) : from(a), to(b), w(c) {}

    bool operator<(const edge &other) const {
        return w > other.w;
    }
};

vector<pair<int, int>> adj[2001];

pair<int, vector<edge>> Kruskal(vector<edge> edgeList, int n) {
    int cost = 0;
    DSU ds(n);
    vector<edge> edges;
    priority_queue<edge> q;
    for (int i = 0; i < edgeList.size(); i++)q.push(edgeList[i]);
    while (!q.empty() && ds.forests != 1) {
        if (ds.unite(q.top().from, q.top().to)) {
            cost += q.top().w;
            adj[q.top().from].push_back({q.top().to, q.top().w});
            adj[q.top().to].push_back({q.top().from, q.top().w});
        }
        q.pop();

    }
    if (edges.size() != n - 1)return {-1, vector<edge>()};
    else return {cost, edges};
}

int dis[2001][2001];
int dist[2001];
void dfs(int u,int p,int w=0){
    dist[u]=w;
    for(auto [next,price]:adj[u]){
        if(next!=p && next != u) dfs(next,u,w+price);
    }
}
void solve() {
    int n;
    cin >> n;
    vector<edge> edges((n*(n-1))/2);
    int index=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            if (!x && i != j)return void(cout << "NO");
            if(i<j)edges[index++]=(edge(i, j, x));
            dis[i][j] = x;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dis[i][j] != dis[j][i]) return void(cout << "NO");
        }
    }
    Kruskal(edges, n);
    for (int i = 0; i < n; ++i) {
        dfs(i,i);
        for (int j = 0; j < n; ++j) {
            if(dist[j]!=dis[i][j])return void(cout<<"NO");
        }
    }
    cout<<"YES";
}


int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    allam
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
        if (t)cout << '\n';
    }

}
