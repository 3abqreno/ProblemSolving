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

int g[101][101]={};

void solve() {
    int a,b,c,d,n;cin>>a>>b>>c>>d>>n;
    cout<<"YES\n";
    int x=0,y=0;
    bool flag=0;
    if(a&1)flag=1,y=b-1;
    else flag=0,y=0;
    for (int i = 1; i <= n; ++i) {
    int f;cin>>f;
    while(f){
        g[y][x]=i;
        y+=flag?-1:1;
        if(x<a){
            if(y<0)x++,flag^=1,y++;
            else if(y==b)x++,flag^=1,y--;
        }else{
            if(y<0)x++,flag^=1,y++;
            else if(y==d)x++,flag^=1,y--;
        }
        f--;
    }
    }
    for (int i = 0; i < max(b,d); ++i) {
        for (int j = 0; j < c+a; ++j) {
            if(!g[i][j])cout<<'.';
            else cout<<char(g[i][j]+'a'-1);
        }
        cout<<'\n';
    }
}

int main() {
    int t = 1;
//       freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);

    allam
//    cin >> t;
    while (t--) {
        solve();
//        cout << '\n';
    }

}
