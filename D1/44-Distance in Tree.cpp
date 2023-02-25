#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
typedef long long ll;
int n,k;
ll ans=0;
vector<int>adj[int(50005)];
vector<int>dfs(int u,int p){
    vector<vector<int>>out;
    vector<int>ret(505);
    ret[0]=1;
    for(auto i:adj[u]){
        if(i!=p)out.push_back(dfs(i,u));
    }
    for(auto &i:out){
        for (int j = 0; j < 502; ++j) {
            ret[j+1]+=i[j];
        }
    }
    ll mid=0;
    for (int i = 0; i < out.size(); ++i) {
        for (int j = 0; j <(k)/2; ++j) {
            ans+=ll(out[i][j])*(ret[k-j-1]-out[i][k-j-2]);
            if(j==(k/2-1))mid+=ll(out[i][j])*(ret[k-j-1]-out[i][k-j-2]);
        }
    }
    if(!(k&1))ans-=mid>>1;
    ans+=ret[k];
    return ret;
}
void solve() {
    cin>>n>>k;
    for (int i = 0; i < n-1; ++i) {
        int a,b;cin>>a>>b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    dfs(0,0);
    cout<<ans;
}

int main() {
    int t = 1;
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    cin >> t;
    while (t--) {
        solve();
//        if (t)cout << '\n';
    }

}
