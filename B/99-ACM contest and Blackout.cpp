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
    bool operator == (const edge &other) const {
        return this->to==other.to&&this->from==other.from&& this->w==other.w;
    }
};

pair<int, vector<edge>> Kruskal(vector<edge> edgeList, int n) {
    int cost = 0;
    dsu ds(n);
    vector<edge> edges;
    priority_queue<edge> q;
    for (int i = 0; i < edgeList.size(); i++)q.push(edgeList[i]);
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

void solve() {
    int n, m;
    cin>>n>>m;
    vector<edge> v(m);
    for (int i = 0; i < m; ++i) {
        int a,b,c;
        cin>>a>>b>>c;a--,b--;
        v[i].from=a,v[i].to=b,v[i].w=c;
    }
    pair<int,vector<edge>>p;
    p=Kruskal(v,n);
    int index=0,ans=INT_MAX;
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < m; ++j) {
            if(v[j]==p.second[i]){
                index=j;
                break;
            }
        }
        if(index==-1)cout<<-1;
        int w=v[index].w;
        v[index].w=1e9;
        ans=min(ans, Kruskal(v,n).first);
        v[index].w=w;
        index=-1;

    }
    cout<<p.first<<" "<<ans<<'\n';
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
