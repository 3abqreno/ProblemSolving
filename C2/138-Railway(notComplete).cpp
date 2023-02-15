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
typedef long long ll;
#define X first
#define Y second
#define point pair<double,double>
point m;
point a[100001];
ll cross(point x,point y,point z){
    point v1={y.X-x.X,y.Y-x.Y},v2={x.X-z.X,x.Y-z.Y};
    return v1.X*v2.Y-v1.Y*v2.X;
}
double dis(point x,point y){
    return sqrt((x.X-y.X)*(x.X-y.X)+(x.Y-y.Y)*(x.Y-y.Y));
}

#define rotateO(p,ang)          ((p)*exp(complex<double>(0,ang)))
void solve() {
    int c=0;
while(cin>>m.X>>m.Y){
    c++;
    int n;cin>>n;
    for (int i = 0; i < n+1; ++i)cin>>a[i].X>>a[i].Y;
    double ans=1e9,x,y;
    point aa;
    for (int i = 0; i < n; ++i) {
        ll c=cross(a[i],a[i+1],m);
        double d1=dis(a[i],a[i+1]),d2=dis(a[i],m);
        if(d2<1e-9){
           x=a[i].X,y=a[i].Y;
           break;
        }
        if(d1<1e-9)continue;
        double s=c/(d1*d2),d=c/d2;
        if(m==a[i]){aa=a[i];break;}
        if(m==a[i+1]){aa=a[i+1];break;}
        if(s==0){
            double d3=dis(a[i+1],m);
            if(d2<ans)ans=d2,aa=a[i];
            if(d3<ans)aa=a[i+1],ans=d2;
            continue;
        }
        complex<double> v((a[i].X-m.X)*cos(asin(s)),(a[i].Y-m.Y)*cos(asin(s)));
        v=rotateO(v,asin(-s));
        if(d<ans){
            ans=d;
            aa={m.X+v.real(),m.Y+v.imag()};
        }
    }

    cout<<fixed<<setprecision(4)<<aa.X<<"\n"<<aa.Y<<'\n';
}
}

int main() {
    int t = 1;
//       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
//        cout << '\n';
    }

}
