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

__int128 lcm2(ll a,ll b){
    return a*__int128(b/__gcd(a,b));
}

void solve() {
    ll t,w,b;cin>>t>>w>>b;
    if(b>w)swap(b,w);
    if(w==b||t<b)return void(cout<<"1/1");
    __int128 lc=lcm2(w,b);
    ll cnt=t/lc,ans=b-1,g;
    if(cnt)ans+=(cnt-1)*b+!!cnt+min(ll(t%lc),b-1);
    g=__gcd(ans,t);
   cout<<(ans/g)<<"/"<<t/g;
}

int main() {
    int t = 1;
    //   freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);

    allam
//    cin >> t;
    while (t--) {
        solve();
        if(t)cout << '\n';
    }

}
