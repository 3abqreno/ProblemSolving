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

ll a[int(2e5+5)];
ll c[int(2e5+5)]={};
void solve() {
int n,k;cin>>n>>k;
map<ll,vector<int>>mp;
map<ll,ll>t;
for(int i=0;i<n;i++){cin>>a[i];mp[a[i]].push_back(i);}
    for (int i = n-2; ~i  ; --i) {
      if(mp.contains(a[i]*k)){
          auto it= upper_bound(all(mp[a[i]*k]),i);
          t[a[i]]+=mp[a[i]*k].end()-it;
          c[i]=t[a[i]];
      }
    }
    ll ans=0;
    for (int i = 0; i < n; ++i) {
        if(mp.contains(a[i]*k)){
            auto it= upper_bound(all(mp[a[i]*k]),i);
            if(it==mp[a[i]*k].end())continue;
            ans+=c[*it];
        }
    }
    cout<<ans;
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
