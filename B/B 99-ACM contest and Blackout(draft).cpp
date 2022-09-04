//   _____       _
//  |____ |     | |
//     / / __ _| |__   __ _ _ __ ___ _ __   ___
//      \ \/ _` | '_ \ / _` | '__/ _ \ '_ \ / _ \
//  .___/ / (_| | |_) | (_| | | |  __/ | | | (_) |
//  \____/ \__,_|_.__/ \__, |_|  \___|_| |_|\___/
//                       | |
//                       |_|
#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#include <unordered_map>

#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
#define F first
#define S second
using namespace std;
typedef long long ll;
const double pi = 3.14159265358979323846;
#define MOD 1000000007
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);


long long gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll fastpow(ll b, ll e) {
    if (!e) {
        return 1;
    }
    if (e & 1) {
        return b * fastpow(b, e - 1) % MOD;
    }
    ll x = fastpow(b, e / 2) % MOD;
    return x * x % MOD;
}

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

class DSU {
    int *parent;
    int *rank;

public:
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // Find function
    int find(int i) {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    // Union function
    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            } else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

vector<ll> add;

class Graph {
    vector<vector<int>> edgelist;
    int V;

public:
    Graph(int V) { this->V = V; }

    void addEdge(int x, int y, int w) {
        edgelist.push_back({w, x, y});
    }

    pair<ll,ll> kruskals_mst() {
        // 1. Sort all edges
        sort(edgelist.begin(), edgelist.end());

        // Initialize the DSU
        int ans = 0;
        {
            DSU s(V);
            for (int i = 0; i < edgelist.size(); i++) {
                vector<int> edge = edgelist[i];
                int w = edge[0];
                int x = edge[1];
                int y = edge[2];

                // Take this edge in MST if it does
                // not forms a cycle
                if (s.find(x) != s.find(y)) {
                    add.push_back(i);
                    s.unite(x, y);
                    ans += w;
                }
            }
        }
        int ans_2=ans,m=INT_MAX;
        for (int j = 0;j < add.size(); ++j) {
            ans_2=0;
            DSU s(V);
            int e=0;
            for (int i=0;i<edgelist.size();i++) {
                if(i==add[j]) {
                    continue;
                }
                vector<int>edge=edgelist[i];
                int w = edge[0];
                int x = edge[1];
                int y = edge[2];

                // Take this edge in MST if it does
                // not forms a cycle
                if (s.find(x) != s.find(y)) {
                    if (w != 0)
                    s.unite(x, y);
                    ans_2 += w;
                    e++;
                }
            }
            if(e==V-1)
            m=min(ans_2,m);
        }
        if(m==INT_MAX)m=ans;
        return {ans,m};
    }
};
int f;
void solve() {
    f--;
   int n,m,a,b,c;
   cin>>n>>m;
   Graph g(n);
    for (int i = 0; i < m; ++i) {
        cin>>a>>b>>c;
        a--;
        b--;
        g.addEdge(a,b,c);
    }
    add.clear();
    pair<ll,ll>p=g.kruskals_mst();
    cout<<p.first<<" "<<p.second;
    if(f)cout<<endl;
}


int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", std   out);
    allam
    int t = 1;
    cin >> t;
    f=t;
    while (t--) {
        solve();
    }

}
