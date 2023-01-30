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
const int MOD=1e8;
int n1,n2,k1,k2;
int dp[102][102][12][12];
int go(int i,int j,int k,int l){
if(k>k1||l>k2||i>n1||j>n2)return 0;
if(i==n1&&n2==j)return 1;
int &ret=dp[i][j][k][l];
if(~ret)return ret;
ret=(go(i,j+1,0,l+1)+go(i+1,j,k+1,0))%MOD;
return ret;
}
void solve() {
    memset(dp,-1,sizeof dp);
cin>>n1>>n2>>k1>>k2;
cout<<go(0,0,0,0);
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
