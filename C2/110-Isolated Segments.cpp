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
struct point{
    int x,y;
    point(int x=0,int y=0):x(x),y(y){}
    point operator -(point other){
        return point(x-other.x,y-other.y);
    }
    inline bool operator ==(point other){
        return x==other.x&&y==other.y;
    }
};
struct seg{
    point a,b;
};
const int N=50;
seg arr[N];
double EPS=1e-8;
long long  cross(point &v1,point &v2){
    return  1ll*v1.x*v2.y-1ll*v1.y*v2.x;
}
double norm(point v1){
    return sqrt((v1.x*v1.x)+(v1.y*v1.y));
}
int ccw(point &a,point &b,point &c){
    point v1=b-a;
    point v2=c-a;
    if(cross(v1,v2) >EPS)return 1;
    if(cross(v1,v2) <-EPS)return -1;
    if(v1.x*v2.x < -EPS || v1.y*v2.y < -EPS)return -1;
    if(norm(v1) < norm(v2)-EPS)return 1;
    return 0;
}
bool Inter(seg f,seg s){
    point a=f.a,b=f.b,c=s.a,d=s.b;
    point v1=b-a;
    point v2=d-c;
    bool f1=(a==b),f2=(c==d);
    if(f1&&f2)return a==c;
    if(f1)return ccw(c,d,a)==0;
    if(f2)return ccw(a,b,c)==0;
    return ccw(a,b,c) * ccw(a,b,d)<=0&&
           ccw(c,d,a) * ccw(c,d,b)<=0;
}
int c=0;
void solve() {
    int n;cin>>n;
    for (int i = 0; i < n; ++i) cin>>arr[i].a.x>>arr[i].a.y>>arr[i].b.x>>arr[i].b.y;

    int ans=n;
    vector<int>adj(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
           if(Inter(arr[i],arr[j]))adj[i]=adj[j]=1;
        }
    }
for(auto i:adj)ans-=i;
cout<<ans;

}

int main() {
    int t = 1;
//       freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);

    allam
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }

}
