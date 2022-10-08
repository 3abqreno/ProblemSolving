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


void solve() {
    int n,m;
    cin>>n>>m;
    string s[n],ans[n];
    for (int i = 0; i < n; ++i) ans[i]="";
    for (int i = 0; i < n; ++i) {
        cin>>s[i];
    }
    int cnt=0;
    for (int i = 0; i < m; ++i) {
        bool ok=1;
        for (int j = 1; j <n ; ++j) {
            if((ans[j]+s[j][i])<(ans[j-1]+s[j-1][i])){
                ok=0;break;
            }
        }
        if(!ok)cnt++;
        else{
            for (int j = 0; j < n; ++j) {
                ans[j]+=s[j][i];
            }
        }
    }
    cout<<cnt;
}
int main() {

//    freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
    allam
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }

}
