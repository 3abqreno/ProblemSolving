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


long long gcd(ll a, ll b) {
    if (b == 0)
        return a;
    if (a == 0)
        return b;
    return gcd(b, a % b) % MOD;
}

long long lcm(int a, int b) {
    if (a == 1 && b == 1) {
        return 1;
    }
    return (a / gcd(a, b)) * b;
}


long long fast_power(long long base, long long power) {
    long long result = 1;
    while (power > 0) {

        if (power % 2 == 1) {
            result = (result * base);
        }
        base = (base * base);
        power >>= 1;
    }
    return result;
}

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};


void solve() {

    int n, m, sx, sy, fx, fy, a, b, x, y;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') {
                sx = i, sy = j;
            }
            if (grid[i][j] == 'F') {
                fx = i, fy = j;
            }
        }
    }
    vector<vector<pair<int,int>>>dis(n,vector<pair<int,int>>(m,{1e6,-1}));
    queue<pair<int,pair<int,int>>> q;
    q.push({sx,{sy,-1}});
    dis[sx][sy] = {0,0};
    while (q.size()) {
        a = q.front().first;
        b = q.front().second.first;
        for (int i = 0; i < 8; ++i) {
            x = a + dx[i];
            y = b + dy[i];
            while (x >= 0 && x < n && y >= 0 && y < m && grid[x][y]!='X'&& dis[x][y].first>=(dis[a][b].first + 1)&&dis[x][y].second!=i) {
                dis[x][y]= {dis[a][b].first + 1,i};
                if(x==fx&&y==fy){
                    cout<<dis[x][y].first<<'\n';
                    return;
                }
                q.push({x,{y,i}});
                x = x + dx[i];
                y = y + dy[i];
            }
        }
        q.pop();
    }
    cout << -1;
}


int main() {
    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    allam
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

}
