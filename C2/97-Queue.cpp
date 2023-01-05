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
int dy[6] = {0,0,1, -1, 1, -1};
int dx[6] = {1,-1,1, -1, -1, 1};


void solve() {
   int n;cin>>n;
   vector<pair<int,string>>v(n);
   for(auto &[i,j]:v)cin>>j>>i;
   sortv(v);
    vector<pair<string,int>>ans;
    for (int i = 0; i < n; ++i) {
    if(v[i].first>i)return void(cout<<-1);
    ans.insert(ans.begin()+v[i].first,{v[i].second,1e9-v[i].first});
    }
    for(auto [i,j]:ans)cout<<i<<" "<<j<<'\n';



}


    int main() {
        int t = 1;
    //   freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }

}
