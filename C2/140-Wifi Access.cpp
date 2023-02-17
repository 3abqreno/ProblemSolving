//   _____       _
//  |____ |     | |
//      / / __ _| |__   __ _ _ __ ___ _ __   ___
//      \ \/ _` | '_ \ / _` | '__/ _ \ '_ \ / _ \
//  .___/ / (_| | |_) | (_| | | |  __/ | | | (_) |
//  \____/ \__,_|_.__/ \__, |_|  \___|_| |_|\___/
//                       | |
//                       |_|
#include <bits/stdc++.h>
using namespace std;
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
#define point pair<int,int>
#define X first
#define Y second
typedef long long ll;
int r[101];
point p[101];
bool check(int i,point u){
    return (r[i]*r[i])>=((p[i].X-u.X)*(p[i].X-u.X)+(p[i].Y-u.Y)*(p[i].Y-u.Y));
}
void solve() {
int n,c;cin>>n>>c;
    for (int i = 0; i < n; ++i)cin>>p[i].X>>p[i].Y>>r[i];
    for (int i = 0; i < c; ++i) {
        int x,y,ok=0;cin>>x>>y;
        for (int j = 0; j < n; ++j) {
            if(check(j,{x,y})){ok=1;break;}
        }
        cout<<(ok?"Yes\n":"No\n");
    }
}

int main() {
    int t = 1;
//       freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);
    allam
    int c=1;
    cin >> t;
    while (t--) {
        cout<<"Case "<<c++<<":\n";
        solve();
//        cout << '\n';
    }

}
