
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
        return b * fastpow(b, e - 1);
    }
    ll x = fastpow(b, e / 2);
    return x * x;
}


int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

void solve() {
    string s;
    bool dash=1;
    vector<string> grid;
    while (true) {
        getline(cin, s);
        dash=1;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i]!='_'){
                dash=0;
                break;
            }
        }
        if(dash)break;
        if (s != "")
            grid.push_back(s);
    }
    int x = -1, y = -1;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == '*') {
                x = i, y = j;
                break;
            }
        }
        if (x != -1)break;
    }
    queue<pair<int, int>> q;
    q.push({x, y});
    map<pair<int, int>, bool> vis;
    grid[x][y] = '#';
    vis[{x, y}] = 1;
    int a, b;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        for (int i = 0; i < 8; ++i) {
            a = x + dx[i];
            b = y + dy[i];
            if (a < grid.size() && b >= 0 && a >= 0 && b < grid[a].size()) {
                if (vis.find({a, b}) == vis.end() && grid[a][b] == ' ') {
                    vis[{a, b}] = 1;
                    q.push({a, b});
                    grid[a][b] = '#';
                }
            }
        }
        q.pop();
    }
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout<<s<<endl;

}


int main() {
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    // allam
    int t = 1;
    cin >> t;
    string c;
    getline(cin,c);
    while (t--) {
        solve();
    }

}
