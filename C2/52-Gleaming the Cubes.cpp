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
int dx[8] = {0, 0, 1,0};
int dy[8] = {1, -1, 0,1};

void solve(){
    int n;
    while(cin>>n){
        if(!n)return;
     int x1=0,y1=0,z1=0,x2=1e7,y2=1e7,z2=1e7;
        for (int i = 0; i < n; ++i) {
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            x1=max(a,x1);
            y1=max(b,y1);
            z1=max(c,z1);
            x2=min(a+d,x2);
            y2=min(b+d,y2);
            z2=min(c+d,z2);
        }
        if(x1>x2||y1>y2||z1>z2)cout<<("0\n");
        else cout<<(x2-x1)*(y2-y1)*(z2-z1)<<'\n';
    }
}


int main() {
    int t = 1;
    //   freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
//        cout << '\n';
    }

}
