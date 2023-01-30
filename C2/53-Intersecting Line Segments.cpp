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

int a[10000][4];
pair<double, double> equ[10000];
//f => ax
//s => b
bool  intersect(int i,int j){
auto [x,y]=equ[i];
auto [x2,y2]=equ[j];
if(x==-1e9&&x2==-1e9)return 0;
if(x==x2&&y==y2)return 0;
if(x==-1e9){
double yy=x2*y+y2;
return (yy>=min(a[i][1],a[i][3])&&yy<=max(a[i][1],a[i][3]));
}else if(y==-1e9){
    double yy=x*y2+y;
    return (yy>=min(a[j][1],a[j][3])&&yy<=max(a[j][1],a[j][3]));
}
double xx=((y2-y)/(x-x2));
double yy=xx*x+y;
if((yy>=min(a[i][1],a[i][3])&&yy<=max(a[i][1],a[i][3]))&&(yy>=min(a[j][1],a[j][3])&&yy<=max(a[j][1],a[j][3]))){
    if((xx>=min(a[i][0],a[i][2])&&xx<=max(a[i][0],a[i][2]))&&(xx>=min(a[j][0],a[j][2])&&xx<=max(a[j][0],a[j][2]))){
        return 1;
    }
}
return 0;

}
void solve() {
    int n;cin>>n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
            if (a[i][0] == a[i][2])equ[i] = {-1e9, a[i][0]};
            else if (a[i][1] == a[i][3])equ[i] = {0, a[i][1]};
            else {
                equ[i].first=(a[i][1] - a[i][3]) / double(a[i][0] - a[i][2]);
                equ[i].second=a[i][1]-equ[i].first*a[i][0];
            }
        }
        int ans=n;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                ans+=2*intersect(i,j);
            }
        }
        cout<<ans<<'\n';
}

int main() {
    int t = 1;
    //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);

    allam
    cin >> t;
    while (t--) {
        solve();
        if(t)cout << '\n';
    }

}
