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

#define X first
#define Y second
using namespace std;


double area(pair<int,int>a,pair<int,int>b,pair<int,int>c){
    return ((b.X-a.X)*(c.Y-b.Y)-(b.Y-a.Y)*(c.X-b.X))*0.5;
}

pair<int,int>a[301];
void solve() {
int n;cin>>n;
for(int i=0;i<n;i++)cin>>a[i].X>>a[i].Y;
double ans=0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            double  aP=-1e9,aN=-1e9;
            for (int k = 0; k < n; ++k) {
            if(k==i||k==j)continue;
            double c=area(a[i],a[j],a[k]);
            if(c<0)aN=max(aN,-c);
            else aP=max(aP,c);
            }
            if(aP<0||aN<0)continue;
            else ans=max(ans,aP+aN);
        }
    }
    cout<<fixed<<setprecision(12)<<ans;
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
