#include <bits/stdc++.h>

#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
#define Mask bitset<12>
using namespace std;
typedef long long ll;

int n,m,k;
int c[19][19]{};
int a[19];
ll dp[1<<18][19];
ll go(int mask,int prev){
    if(n-__builtin_popcount(mask)==m)return 0;
    ll &ret=dp[mask][prev];
    if(~ret)return ret;
    for (int i = 0; i < 18; ++i) {
        if(mask&(1<<i)){
            ret=max(ret,a[i]+c[prev][i]+go(mask^(1<<i),i));
        }
    }
    return ret;
}
void solve() {
    memset(dp,-1,sizeof dp);
    cin>>n>>m>>k;
    int mask=0;
    for (int i = 0; i < n; ++i){
        cin>>a[i];
        mask|=(1<<i);
    }
    for (int i = 0; i < k; ++i) {
        int x,y,t;cin>>x>>y>>t;
        c[x-1][y-1]=t;
    }
    ll ans=0;
    for(int i=0;i<n;i++)ans=max(ans,go(mask^(1<<i),i)+a[i]);
    cout<<ans;

}


int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    allam

    int _t = 1;
//    cin >> _t;
    while (_t--) {
        solve();
       cout << '\n';
    }

}
