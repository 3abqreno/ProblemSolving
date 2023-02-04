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

int a[10000][4];
pair<double, double> equ[10000];
//f => ax
//s => b
bool  intersect(int i,int j){
    if((a[i][0]==a[j][0]&&a[i][1]==a[j][1])||(a[i][0]==a[j][2]&&a[i][1]==a[j][3])||(a[i][2]==a[j][0]&&a[i][3]==a[j][1])||(a[i][2]==a[j][2]&&a[i][3]==a[j][3]))return 1;
    auto [x,y]=equ[i];
    auto [x2,y2]=equ[j];
    if(x==x2&&y==y2){
        bool ok=0;
        if(((a[j][1]>=min(a[i][1],a[i][3])&&a[j][1]<=max(a[i][1],a[i][3]))&&(a[j][0]>=min(a[i][0],a[i][2])&&a[j][0]<=max(a[i][0],a[i][2])))||
                ((a[j][3]>=min(a[i][1],a[i][3])&&a[j][3]<=max(a[i][1],a[i][3]))&&(a[j][2]>=min(a[i][0],a[i][2])&&a[j][2]<=max(a[i][0],a[i][2]))))ok=1;
        if(((a[i][1]>=min(a[j][1],a[j][3])&&a[i][1]<=max(a[j][1],a[j][3]))&&(a[i][0]>=min(a[j][0],a[j][2])&&a[i][0]<=max(a[j][0],a[j][2])))||
           ((a[i][3]>=min(a[j][1],a[j][3])&&a[i][3]<=max(a[j][1],a[j][3]))&&(a[i][2]>=min(a[j][0],a[j][2])&&a[i][2]<=max(a[j][0],a[j][2]))))ok=1;
    return ok;
    }
    if(x==-1e9){
        double yy=x2*y+y2;
        return (yy>=min(a[i][1],a[i][3])&&yy<=max(a[i][1],a[i][3])&&y>=min(a[j][0],a[j][2])&&y<=max(a[j][0],a[j][2]));
    }else if(x2==-1e9){
        double yy=x*y2+y;
        return (yy>=min(a[j][1],a[j][3])&&yy<=max(a[j][1],a[j][3])&&y2>=min(a[i][0],a[i][2])&&y2<=max(a[i][0],a[i][2]));
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
int g[14][14]={};
int c=0;
void solve() {
    memset(g,0,sizeof g);
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
        for (int j = i; j < n; ++j) {
           g[i][j]=g[j][i]=intersect(i,j);
        }
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i <n ; ++i)
            for (int j = 0; j <n ; ++j)
                g[i][j]|=(g[i][k]&&g[k][j]);
    int x,y;
    while(cin>>x>>y&&x){c++;
        cout<<(g[x-1][y-1]?"CONNECTED\n":"NOT CONNECTED\n");}


}

int main() {
    int t = 1;
    //   freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);

    allam
    cin >> t;
    while (t--) {
        solve();
        if(t)cout << '\n';
    }

}
