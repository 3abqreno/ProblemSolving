#include <bits/stdc++.h>

#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;

vector<int>adj[1001];
vector<array<int,3>>v;
bool hasParent[1001]={};
bool isInside(array<int,3>a,array<int,3>b){
    ll dis=(ll(a[1]-b[1])*(a[1]-b[1])+ll(b[2]-a[2])*(b[2]-a[2]));
    return dis<=ll(b[0])*b[0];
}
double ans=0;
double area(int r){
    return numbers::pi*ll(r)*r;
}

void dfs(int u,int d){

    if(!d||d==1)ans+= area(v[u][0]);
    else{
        if(d&1)ans+= area(v[u][0]);
        else ans-=area(v[u][0]);
    }
    for(auto &i:adj[u]){
        dfs(i,d+1);
    }

}
void solve() {
    int n;cin>>n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i][1]>>v[i][2]>>v[i][0];
    }
    sortv(v);
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(isInside(v[i],v[j])){
                hasParent[i]=1;
                adj[j].push_back(i);
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if(!hasParent[i])dfs(i,0);
    }
    cout<<fixed<<setprecision(12)<<ans;
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
