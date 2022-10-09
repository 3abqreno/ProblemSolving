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
int dp[105][105];
string s1, s2;
int c = 0;

int lcs(int i, int j) {
    if (i == s1.size() || j == s2.size()) {
        return 0;
    }
    if (dp[i][j] != -1)return dp[i][j];
    if (s1[i] == s2[j]) {
        return 1 + lcs(i + 1, j + 1);
    }
    int c1 = lcs(i + 1, j);
    int c2 = lcs(i, j + 1);
    dp[i][j] = max(c1, c2);
    return dp[i][j];
}

void solve() {
    while (true) {
        getline(cin, s1);
        if (s1 == "#")return;
        getline(cin, s2);
        memset(dp, 0, sizeof dp);
        c++;
        int ans = 0;
        for (int i = 1; i <= s1.size(); ++i) {
            for (int j = 1; j <= s2.size(); ++j) {
                if (s1[i-1] == s2[j-1]){
                    dp[i][j] =dp[i-1][j-1]+ 1;
                }
             else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

            }

        }
        cout << "Case #" << c << ": you can visit at most " << dp[s1.size()][s2.size()] << " cities." << '\n';
    }
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
