
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
using namespace std;
typedef long long ll;
const double pi = 3.14159265358979323846;
#define MOD 1000000007
#define fast  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1, -1};
int dy[8] = {1, -1, 0, 0};

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
        return b * fastpow(b, e - 1);
    }
    ll x = fastpow(b, e / 2);
    return x * x;
}

int n, m;
vector<vector<char>> grid;
bool vis[51][51] = {0};

bool dfs(int i, int j, int pi = -1, int pj = -1) {
    vis[i][j] = 1;
    int x, y;
    for (int k = 0; k < 4; ++k) {
        x = i + dx[k];
        y = j + dy[k];
        if (x < n && x >= 0 && y < m && y >= 0) {
            if (grid[x][y] == grid[i][j]) {
                if (vis[x][y] && (x != pi || y != pj)) {
                    return true;
                } else if (!vis[x][y])if(dfs(x, y, i, j))return true;
            }
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(!vis[i][j])
            {
                if(dfs(i,j)){
                    cout<<"Yes";
                    return;
                }
            }
        }
    }
    cout<<"No";

}


int main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt", "w", stdout);
    fast
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

}
