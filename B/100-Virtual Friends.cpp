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
    unordered_map<string, string>  parent;
    unordered_map<string,int>rank;
    int forests;
    dsu() {}
//    dsu(int n) {
//        rank.assign(n, 1);
//        parent.assign(n, -1);
//        forests = n;
//    }

    bool unite(string a, string b) {
        string x = find(a), y = find(b);
        if (find(a) != find(b)) {
            forests--;
            if (rank[x] > rank[y])parent[y] = x, rank[x] += rank[y];
            else parent[x] = y, rank[y] += rank[x];
            return 1;
        } else return 0;
    }

    string find(string a) {
        if (parent[a] == "")return a;
        return parent[a] = find(parent[a]);
    }

};


void solve() {
    int n;
    cin >> n;
    dsu d;
    for (int i = 0; i < n; ++i) {
        string a,b;
        cin>>a>>b;
        if(d.rank.find(a)==d.rank.end())d.rank[a]=1;
        if(d.rank.find(b)==d.rank.end())d.rank[b]=1;
        d.unite(a,b);
        cout<<d.rank[d.find(a)]<<"\n";
    }
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
