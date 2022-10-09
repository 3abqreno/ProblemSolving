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

long long fast_power(long long base, long long power) {
    long long result = 1;
    while (power > 0) {

        if (power % 2 == 1) {
            result = (result * base);
        }
        base = (base * base);
        power >>= 1;
    }
    return result;
}

int dx[8] = {0, 0, 1, -1, 0};
int dy[8] = {1, -1, 0, 0, 0};
bool dp[105][50005] = {};
int coins[105] = {};
int t = 1;

void solve() {
    memset(dp,0,sizeof dp);
    int n, total = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
        total += coins[i];
    }
    if(n==0){
        cout<<0<<'\n';
        return;
    }
    dp[0][0] = 1;
    dp[0][coins[0]] = 1;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j <= 50000; ++j) {
            if (dp[i][j]) {
                dp[i + 1][j] = 1;
                dp[i + 1][j + coins[i+1]] = 1;
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i <= 50000; ++i) {
        if (dp[n - 1][i]) {
            ans = min(ans, abs(i - (total- i)));
        }
    }
    cout<<ans<<'\n';
}

int main() {

    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    allam
    cin >> t;
    while (t--) {
        solve();
    }

}
