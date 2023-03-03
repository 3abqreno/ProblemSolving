
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
typedef long long ll;

vector<int>adj[int(200000+5)];
pair<int,int> good[int(200000+5)]={};
vector<int>ans;
deque<int>bad;
void dfs(int u=0,int p=0,int depth=0){
    if(!good[u].second)bad.push_back(u);
    if(bad.size()>depth/2){
        good[bad.front()].second=1;
        ans.push_back(good[bad.front()].first);
        bad.pop_front();
    }
    for(auto i:adj[u]){
        if(i!=p)dfs(i,u,depth+1);
    }
    if(!bad.empty()&&bad.back()==u)bad.pop_back();
}
void solve(){
int n;cin>>n;
    for (int i = 0; i < n-1; ++i) {
        int a,b,c;cin>>a>>b;
        string s;cin>>s;
        good[a-1]={i,1};
        adj[--b].push_back({--a});
        if(s!="protected")cin>>s,good[a].second=0;
    }
    for(auto i:adj[0]){
        dfs(i,0,1);
    }
    cout<<ans.size()<<'\n';
    for(auto &i:ans)cout<<i+1<<' ';
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
        if (t)cout << '\n';
    }

}
