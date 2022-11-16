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

#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

int grid[101][101];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    if(n&1)cout<<n;
    else{
        int temp=n,ans=n;
        bool ok=1;
        while(ok&&!(temp&1)) {
            temp>>=1;
            for (int i = 0; i < temp&&ok; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (grid[i][j] != grid[2 * temp - i-1][j]){
                        ok=0;
                        break;
                    }
                }
            }
            if(ok)
            ans=temp;
        }
         cout<<ans;
    }

}

int main() {
    int t = 1;
    //    freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
    }

}
