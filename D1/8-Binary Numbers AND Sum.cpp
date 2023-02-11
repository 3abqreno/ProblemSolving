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
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
typedef long long ll ;
const int mod=998244353;
int p[int(2e5+5)];
void solve() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int ans=0,c=0;
    if(m>=n) {
        for (int i = 0; i < m - n; i++)c += b[i] == '1';
        for (int i = m - n, j = 0, x = n - 1; i < m; i++, x--, j++) {
            c += b[i] == '1';
            if (a[j] == '1')ans = (ans + ll(p[x]) * c) % mod;
        }
    }
    else{
        for (int i = 0,x=m-1; i < m; i++,x--) {
            c += b[i] == '1';
            if (a[n-m+i] == '1')ans = (ans + ll(p[x]) * c) % mod;
        }
    }
    cout<<ans;

}
int main() {
    int t = 1;
//       freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);
    int x=1;
    p[0]=1;
    for (int i = 1; i < 2e5+1; ++i) {
        x=(x<<1)%mod;
        p[i]=x;
    }
    allam
//    cin >> t;
    while (t--) {
        solve();
//        cout << '\n';
    }

}
