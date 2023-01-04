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
  int a,b;cin>>a>>b;
    for (int i = 1; i <a ; ++i) {
        int x=sqrtl(a*a-i*i);
        if(x*x==(a*a-i*i)&&(x*b)%a==0&&(i*b)%a==0&&(i*b)/a!=x){
        cout<<"YES\n"<<"0 0\n";
        cout<<i<<" "<<x<<'\n';
        cout<<-(x*b)/a<<" "<<(i*b)/a;
            return;
        }
    }
    cout<<"NO\n";
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
