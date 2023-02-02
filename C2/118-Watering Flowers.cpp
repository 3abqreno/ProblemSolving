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
#define  x first
#define y second
pair<ll,ll> dis[2005];
void solve() {
    int n,x1,y1,x2,y2;cin>>n>>x1>>y1>>x2>>y2;
    vector<pair<int,int>>v(n);
    for(int c=0;auto &[i,j]:v){
        cin>>i>>j;
        dis[c].first=(i-x1)*(ll(i)-x1)+(ll(j)-y1)*(j-y1);
        dis[c++].second=(i-x2)*(ll(i)-x2)+(ll(j)-y2)*(j-y2);
    }
    sort(dis,dis+n);
    ll ans=3e18;
    for (int i = -1; i < n; ++i) {
        ll a1=0,a2=0;
        if(~i)a1=dis[i].x;
        for (int j = i+1; j < n; ++j)a2=max(a2,dis[j].y);
        ans=min(ans,a1+a2);
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
