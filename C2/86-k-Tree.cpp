//   _____       _
//  |____ |     | |
//      / / __ _| |__   __ _ _ __ ___ _ __   ___
//      \ \/ _` | '_ \ / _` | '__/ _ \ '_ \ / _ \
//  .___/ / (_| | |_) | (_| | | |  __/ | | | (_) |
//  \____/ \__,_|_.__/ \__, |_|  \___|_| |_|\___/
//                       | |
//                       |_|
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int n,k,d;
const int MOD =1e9+7;
int dp[105][2];
int go(int c,int t){
    if(c>n)return 0;
    int & res=dp[c][t];
    if(c==n&&t)return 1;
    if(~res)return res;
    res=0;
    for (int j = 1; j <= k; ++j) {
        res=(res+go(c+j,t|(j>=d)))%MOD;
    }
    return res;
}

void solve() {
    memset(dp,-1,sizeof dp);
    cin>>n>>k>>d;
    int ans=0;
    for (int i = 1; i <=k ; ++i)ans=(ans+go(i,i>=d))%MOD;
    cout<<ans;
}

int main() {
    int t = 1;
    //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);

    allam
//    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }

}
