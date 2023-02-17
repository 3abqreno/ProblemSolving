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
typedef complex<double> point;
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
const long double pii=3.141592653589793;
const double eps=1e-9;
point a,b,c;
vector<pair<double,double>>lines;
void findlines(point e,point d){
    point v= vec(e,d);
    v/=2;
    point md=(e+d);md/=2;
    v= rotateO(v,pii/2);
    point other=md+v;
    if(abs(md.X-other.X)<eps){
        lines.push_back({-1e9,md.X});
        return;
    }
    double xx=md.Y-other.Y,yy=md.X-other.X;
    double slope=(md.Y-other.Y)/(md.X-other.X),m=md.Y-slope*md.X;
    lines.emplace_back(slope,m);
}
void solve() {
    double x,y;
    while(cin>>x>>y){
        lines.clear();
        a=point(x,y);
    cin>>x>>y;b=point(x,y);
    cin>>x>>y;c=point(x,y);
    findlines(a,b);
    findlines(a,c);
    sortv(lines);
    if(lines[0].first==-1e9)x=lines[0].second;
    else x=(lines[1].second-lines[0].second)/(lines[0].first-lines[1].first);
    y=lines[1].first*x+lines[1].second;
    long double r=sqrtl((a.X-x)*(a.X-x)+(a.Y-y)*(a.Y-y));
    long double c=2*pii*r;
    cout<<fixed<<setprecision(2)<<c<<'\n';
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
        if(t)cout << '\n';
    }

}
