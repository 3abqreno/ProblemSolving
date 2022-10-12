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
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set_ll tree<ll, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<ll , null_type ,  less_equal<ll> , rb_tree_tag , tree_order_statistics_node_update>
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;
const double pi = 3.14159265358979323846;
#define MOD 1000000007
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

long long gcd(ll a, ll b) {
    if (b == 0)
        return a;
    if (a == 0)
        return b;
    return gcd(b, a % b) % MOD;
}

long long lcm(int a, int b) {
    if (a == 1 && b == 1) {
        return 1;
    }
    return (a / gcd(a, b)) * b;
}

int n;
ll c[100005];
string s[100005];
string r[100005];
ll dp[100005][2]={};
void solve() {
    memset(dp,0x3f,sizeof dp);
    ll inf=dp[0][0];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        r[i]=s[i];
        reverse(all(r[i]));
    }
    dp[0][0]=0;dp[0][1]=c[0];
    for (int i = 0; i < n-1; ++i) {
        if(s[i]<=s[i+1]){
            dp[i+1][0]=dp[i][0];
        }
        if(r[i]<=s[i+1]){
            dp[i+1][0]=min(dp[i][1],dp[i+1][0]);
        }
        if(s[i]<=r[i+1]){
            dp[i+1][1]=min(dp[i][0]+c[i+1],dp[i+1][1]);
        }
        if(r[i]<=r[i+1]){
            dp[i+1][1]=min(dp[i+1][1],dp[i][1]+c[i+1]);
        }
    }
    ll ans=min(dp[n-1][0],dp[n-1][1]);
    if(ans==inf)cout<<-1;
    else cout<<ans;
}


int main() {
    int t = 1;
    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
    }

}
