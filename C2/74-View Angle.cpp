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
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};


void solve() {
int n;cin>>n;
if(n==1)return void(cout<<0);
vector<double>angles(n);
    for (int i = 0; i < n; ++i) {
        int a,b;cin>>a>>b;
        angles[i]= atan2(b,a)*180/numbers::pi;
        if(angles[i]<0)angles[i]+=360;
    }
    sortv(angles);
    if(n==2){
        double ans=(angles.back()-angles.front());
        if(ans>180)ans-=180;
        return void(cout<<fixed<<setprecision(12)<<ans);
    }
    double ans=500;
    for (int i = 1; i < n; ++i) {
        ans=min(ans,360-(angles[i]-angles[i-1]));
    }
    cout<<fixed<<setprecision(12)<<min(ans,angles.back()-angles.front());
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
