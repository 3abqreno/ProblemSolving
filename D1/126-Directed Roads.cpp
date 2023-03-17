#include <bits/stdc++.h>

#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;

int vis[int(2e5+5)];
vector<int>adj[int(2e5+5)];
vector<int>cycles;
vector<int>st;
int MOD=1e9+7;
ll fastPow(ll a,ll b){
    ll ret=1;
    while(b){
        if(b&1)ret=(ret*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ret;
}
void dfs(int u,int p){
    vis[u]=1;
    st.push_back(u);
    for(auto &i:adj[u]){
        if(i!=p&&vis[i]==1){
            for (int j = st.size()-2; ~j ; --j) {
                if(st[j]==i){
                    cycles.push_back(st.size()-j);
                    break;
                }
            }
        }else if(!vis[i]){
            dfs(i,u);
        }
    }
    vis[u]=2;
    st.pop_back();
}
int take[int(2e5+5)];
void solve() {
    memset(take,-1,sizeof take);
    int n;cin>>n;
    for (int i = 0; i < n; ++i) {
        int a;cin>>a;
        a--;
        if(take[a]==i)cycles.push_back(2);
        take[i]=a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        if(!vis[i])dfs(i,-1);
    }
    int tot=n;
    for(auto &i:cycles)tot-=i;
    ll ans=1;
    for (int i = 0; i < cycles.size(); ++i) {
        ans=(ans*(fastPow(2,cycles[i])-2))%MOD;
    }
    ans=(ans*fastPow(2,tot))%MOD;
    cout<<ans;

}

int main() {
    //freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
    allam
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }

}
