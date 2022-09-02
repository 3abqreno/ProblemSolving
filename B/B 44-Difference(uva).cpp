
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

vector<vector<ll>>dep;
vector<vector<ll>>par;
vector<ll>t;
bool vis[501];
ll dfs(int x){
    vis[x]=1;
    int s=t[x];
    for(auto i:dep[x]){
        if(!vis[i])
        s+=dfs(i);
    }
    return s;
}
ll dfs_p(int x){
    vis[x]=1;
    int s=t[x];
    for(auto i:par[x]){
        if(!vis[i])
            s+=dfs_p(i);
    }
    return s;
}
int f=0;
void solve() {
    ll n, e;

    while (cin >> n >> e) {
        f++;
        ll sum=0;
        dep.clear();
        par.clear();
        t.clear();
        if(n==0&&e==0)return;
        ll a,b;
        dep.resize(n);
        par.resize(n);
        t.resize(n);
        for (int i = 0; i < n; ++i) {
            cin>>t[i];
            sum+=t[i];
        }
        for (int i = 0; i < e; ++i) {
            cin>>a>>b;
            a--;b--;
            dep[b].push_back(a);
            par[a].push_back(b);
        }
        ll q;
        cin>>q;
        ll x,y;
        cout<<"Case #"<<f<<":\n";
        for (int i = 0; i < q; ++i) {
            cin>>a;
            a--;
            y=0;x=0;
            memset(vis,0,501);
            x=dfs(a);
            y=dfs_p(a)-t[a];
            cout<<sum-y-x<<'\n';
        }
        cout<<"\n";
    }
}


int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
  //  allam
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

}
