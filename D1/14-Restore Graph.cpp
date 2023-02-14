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
typedef long long ll;

vector<int>v[int(1e5+1)];
vector<pair<int,int>>ans;
void solve() {
    int n,x,k;cin>>n>>k;
    for (int i = 0; i < n; ++i) {
    cin>>x;v[x].push_back(i+1);
    }
    if(v[0].size()!=1||(v[1].size()>k))return void(cout<<-1);
    for(auto i:v[1])ans.push_back({v[0][0],i});
    for (int i = 2; i < n; ++i) {
        if(v[i].size()>v[i-1].size()*(k-1))return void(cout<<-1);
        int sz=v[i].size()-1;
        for (int j = 0; j < v[i-1].size(); ++j) {
            int go=k-1;
            while(go--&&~sz){
                ans.push_back({v[i-1][j],v[i][sz]});
                sz--;
            }
        }
    }
    cout<<ans.size()<<'\n';
    for(auto [i,j]:ans)cout<<i<<" "<<j<<'\n';

}

int main() {
    int t = 1;
//       freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }

}
