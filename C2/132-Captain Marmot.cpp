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
typedef complex<double> point;
point p[4][2];
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define rotate0(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about) (rotate0(vec(about,p),ang)+about)
# define pi numbers::pi
const double eps =1e-6;

double dist(double x1,double y1,double x2,double y2){
    return ((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1));}
bool isSame(point a,point b){
    return abs(a.X-b.X)<eps&&abs(a.Y-b.Y)<eps;
}
bool isSquare(point p1,point p2,point p3,point p4){
    if(isSame(p1,p2)||isSame(p1,p3)||isSame(p1,p4)||isSame(p2,p3)||isSame(p2,p4)|isSame(p3,p4))return false;
    double d2=dist(p1.X,p1.Y,p2.X,p2.Y);
    double d3=dist(p1.X,p1.Y,p3.X,p3.Y);
    double d4=dist(p1.X,p1.Y,p4.X,p4.Y);
    if (abs(d2-d3)<eps && abs(2*d2-d4)<eps)
    {   double d=dist(p2.X,p2.Y,p4.X,p4.Y);
        return (abs(d - dist(p3.X,p3.Y,p4.X, p4.Y))<eps && abs(d - d2)<eps);
    }
    if (abs(d3-d4)<eps && abs(2*d3-d2)<eps)
    {
        double d=dist(p2.X,p2.Y,p3.X,p3.Y);

        return (abs(d -dist(p2.X,p2.Y,p4.X, p4.Y))<eps && abs(d - d3)<eps);
    }
    if (abs(d2-d4)<eps && abs(2*d2-d3)<eps)
    {   double d=dist(p2.X,p2.Y,p3.X,p3.Y);
        return (abs(d-dist(p3.X,p3.Y,p4.X, p4.Y))<eps && abs(d- d2)<eps);
    }

    return false;


}
void solve() {
    point x(0,1),y=(1,1);
    for (int i = 0; i < 4; ++i){
        int a,b,c,d;cin>>a>>b>>c>>d;
        p[i][0]=point(a,b),p[i][1]=point(c,d);
    }
    int ans=1e9;
    for (int i = 0; i < 4; ++i) {
        point a= rotateA(p[0][0],(pi/2)*i,p[0][1]);
        for (int j = 0; j < 4; ++j) {
            point b= rotateA(p[1][0],(pi/2)*j,p[1][1]);
            for (int k = 0; k < 4; ++k) {
                point c= rotateA(p[2][0],(pi/2)*k,p[2][1]);
                for (int l = 0; l < 4; ++l) {
                    point d= rotateA(p[3][0],(pi/2)*l,p[3][1]);
                    if(i==2&&k==1&&!l&&!j){
//                        cout<<a.X<<" "<<a.Y<<" "<<c.X<<" "<<c.Y;
                    }
                    if(isSquare(a,b,c,d)) ans=min(ans,i+j+k+l);
                }
            }
        }
    }
    cout<<(ans==1e9?-1:ans);
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
