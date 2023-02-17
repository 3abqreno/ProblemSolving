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
map<pair<point,point>,ll>mp;
point a[701];
int cnt[701*701]={};
void createline(int i,int j){
ll num=a[i].Y-a[j].Y,denom=a[i].X-a[j].X,g=__gcd(num,denom);
num/=g,denom/=g;
if(!denom)return void(mp[{{a[i].X,0},{0,0}}]++);
ll cy=a[i].Y*denom+-a[i].X*num;
g=__gcd(denom,cy);
cy=cy/g;
mp[{{num,denom},{cy,denom/g}}]++;
}
string s;
int c=1;
void solve() {
    mp.clear();
    int n=0;
    c++;
    while(getline(cin,s)&&s!=""){
        stringstream ss;ss<<s;
        ss>>a[n].X>>a[n].Y;
        n++;
    }
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j){
            createline(i,j);
        }
    ll ans=0;
    for(auto [i,j]:mp)ans=max(ans,j);
    for (int i = 1; i <= n+1; ++i) {
        if(i*(i-1)==(ans<<1ll)){ans=i;break;}
    }
    cout<<ans<<'\n';
}

int main() {
    int t = 1;
//       freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);
//    allam

//    cin >> t;
    getline(cin,s);
    stringstream ff;
    ff<<s;
    ff>>t;
    getline(cin,s);
    while (t--) {
        solve();
        if(t)cout << '\n';
    }

}
