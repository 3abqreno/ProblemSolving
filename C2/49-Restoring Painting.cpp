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

void solve() {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    ll arr[]={a+b,a+c,c+d,b+d};
    sort(arr,arr+4);
    cout<<max((n-(arr[3]-arr[0]))*n,0ll);


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
