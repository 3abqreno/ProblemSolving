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
#define MOD 2000000011
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);


long long gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(int a, int b) {
    if (a == 1 && b == 1) {
        return 1;
    }
    return (a / gcd(a, b)) * b;
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

int dx[8] = {0, 0, 1, -1};
int dy[8] = {1, -1, 0, 0};


void solve() {
    ll n,m;
    cin>>n>>m;
    vector<pair<int,int>>v;
    vector<string>s(n);
    for (int i = 0; i < n; ++i) {
        cin>>s[i];
        for (int j = 0; j < m; ++j) {
            if(s[i][j]=='1')v.push_back({i,j});
        }
    }
    ll sz=v.size(),d,temp;
    vector<vector<int>>grid(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>>q;
    for (int i = 0; i < v.size(); ++i) {
        q.push({{v[i].first,v[i].second},0});
    }
    bool vis[n][m];
    for (int i = 0; i < n; ++i) {
        memset(vis[i],0,m);
    }
    int a,b,x,y;
    while(q.size()){
        a=q.front().first.first;
        b=q.front().first.second;
        for (int i = 0; i < 4; ++i) {
            x=a+dx[i];
            y=b+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m&&!vis[x][y]&&s[x][y]=='0'){
                vis[x][y]=true;
                grid[x][y]=q.front().second+1;
                q.push({{x,y},q.front().second+1});
            }
        }
        q.pop();
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", std   out);
    allam
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

}
