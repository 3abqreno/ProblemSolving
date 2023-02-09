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
# define pi numbers::pi
#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p0,p1)             (dp(vec(p0,p1),vec(p0,p1)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
#define polar(r,ang)            ((r)*exp(point(0,ang)))
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  	(rotateO(vec(about,p),ang)+about)
pair<int,int>po[4];
point p[4];
point circle;
pair<double,double>equ[4];
char grid[105][105];
double dis(point a,point b){
    return sqrt((a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y));
}
const double eps=1e-6;
void solve() {

int h,w,cx,cy,r;cin>>w>>h>>cx>>cy>>r>>po[0].first>>po[0].second>>po[1].first>>po[1].second;
    for (int i = 0; i < 105; ++i)for (int j = 0; j < 105; ++j)grid[i][j]='.';
circle=point(cx,cy);
p[0]=point(po[0].first,po[0].second);
p[1]=point(po[1].first,po[1].second);
point v={(p[0].X-p[1].X)/sqrt(2),(p[0].Y-p[1].Y)/sqrt(2)};
p[2]= p[1]+rotateO(v,pi/4);
p[3]= p[1]+rotateO(v,-pi/4);
    for (int i = 0; i <2; ++i) {
        if(p[0].X==p[i+2].X)equ[2*i]={0,p[0].Y};
        else{
            double slope=(p[0].Y-p[i+2].Y)/(p[0].X-p[i+2].X);
            double add=p[0].Y-slope*p[0].X;
            equ[2*i]={slope,add};
        }
        if(p[1].X==p[i+2].X)equ[2*i+1]={0,p[1].Y};
        else{
            double slope=(p[1].Y-p[i+2].Y)/(p[1].X-p[i+2].X);
            double add=p[1].Y-slope*p[1].X;
            equ[2*i+1]={slope,add};
        }

    }
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            double d=dis(point(i,j),circle)-r;
            if(dis(point(i,j),circle)-r<eps){grid[j][i]='#';continue;}
            int ok=0;
            for (int k = 1; k < 2; ++k) {
               d=(p[2+i].X-p[0].X)*(j-p[0].Y)-(i-p[0].X)*(p[2+i].Y-p[0].Y);
               ok+=(d>=0);
                d=(p[2+i].X-p[1].X)*(j-p[1].Y)-(i-p[1].X)*(p[2+i].Y-p[1].Y);
                ok+=(d>=0);
            }
            if(ok==4){grid[j][i]='#';}
        }
        cout<<'\n';
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w   ; ++j) {
            cout<<grid[i][j];
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
        cout << '\n';
    }

}
