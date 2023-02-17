//   _____       _
//  |____ |     | |
//      / / __ _| |__   __ _ _ __ ___ _ __   ___
//      \ \/ _` | '_ \ / _` | '__/ _ \ '_ \ / _ \
//  .___/ / (_| | |_) | (_| | | |  __/ | | | (_) |
//  \____/ \__,_|_.__/ \__, |_|  \___|_| |_|\___/
//                       | |
//                       |_|
#include <bits/stdc++.h>
using namespace std;
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
typedef long long ll;
int dp[5005][5005];
int a,b,c;
const int mod=998244353;
int go(int i,int j){
if(!i||!j)return 1;
int &ret=dp[i][j];
if(~ret)return ret;
ret=(go(i-1,j)%mod+go(i-1,j-1)*1ll%mod*j%mod)%mod;
return ret;
}
void solve() {
    memset(dp,-1,sizeof dp);
    cin>>a>>b>>c;
    cout<<1ll*go(a,b)*go(b,c)%mod*go(c,a)%mod;
}


int main() {
    int t = 1;
//       freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);

    allam

//    cin >> t;
    while (t--) {
        solve();
//        if(t)cout << '\n';
    }

}
