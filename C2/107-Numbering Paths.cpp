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
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;
bool vis[31] = {};
bool ok = 1;

void dfs(int u) {
    vis[u] = 1;

}

int a[31][31] = {};

void solve() {

    int n, mx = 0,c=0;
    while (cin >> n) {
        cout<<"matrix for city "<<c++<<'\n';
        mx=0;memset(a, 0, sizeof a);
        for (int i = 0; i < n; i++) {
            int j, k;
            cin >> j >> k;
            a[j][k]++;
            mx = max({mx, j, k});
        }
        mx++;
        for (int i = 0; i < mx; ++i)
            for (int j = 0; j < mx; ++j)
                for (int k = 0; k < mx; ++k) a[j][k] += a[j][i] * a[i][k];
        if(mx>1)
        for (int i = 0; i < mx; ++i) {
            for (int j = 0; j < mx; ++j) {
                if(!a[i][j])cout<<0;
                else{bool ok=1;
                for (int k = 0; k < mx; ++k) {
                    if(a[i][k]&&a[k][j]&&a[k][k]){ok=0;
                        break;}
                }
                cout<<(ok?a[i][j]:-1);}
                if(j<mx-1)cout << ' ';
            }
            cout << '\n';
        }
    }
    if(mx==1)cout<<'\n';
}

int main() {
    int t = 1;
    //   freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);

    allam
//    cin >> t;
    while (t--) {
        solve();
//        cout << '\n';
    }

}
