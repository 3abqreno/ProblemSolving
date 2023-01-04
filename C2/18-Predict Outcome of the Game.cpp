//   _____       _
//  |____ |     | |
//      / / __ _| |__   __ _ _ __ ___ _ __   ___
//      \ \/ _` | '_ \ / _` | '__/ _ \ '_ \ / _ \
//  .___/ / (_| | |_) | (_| | | |  __/ | | | (_) |
//  \____/ \__,_|_.__/ \__, |_|  \___|_| |_|\___/
//                       | |
//                       |_|
#include <bits/stdc++.h>

#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
ll n,d1,d2,k;

bool check(ll a,ll b,ll c){
return (k-a-b-c)>=0 && (k-a-b-c)%3==0 && (n-k-3*max(a,max(b,c))+a+b+c)>=0&&(n-k-3*max(a,max(b,c))+a+b+c)%3==0;
}
void solve() {
 cin>>n>>k>>d1>>d2;
 ll a,b,c;
 if(n%3){
     cout<<"no\n";
     return;
 }
    bool ok=0;
    a=d1,b=0,c=d2;
    ok|=check(a,b,c);
    a=d1+d2,b=d2,c=0;
    ok|=check(a,b,c);
    a=0,b=d1,c=d1+d2;
    ok|=check(a,b,c);
    a=d2+d1,b=d1,c=0;
    ok|=check(a,b,c);
    a=0,b=d2,c=d1+d2;
    ok|=check(a,b,c);
    a=d2+d1,b=d2,c=0;
    ok|=check(a,b,c);
    a=0,b=d1+d2,c=d1;
    ok|=check(a,b,c);
    a=d2,b=d1+d2,c=0;
    ok|=check(a,b,c);
    a=abs(d1-d2),b=max(d1,d2),c=0;
    ok|=check(a,b,c);
    a=0,b=max(d1,d2),c=abs(d1-d2);
    ok|=check(a,b,c);
    if(ok)cout<<"yes\n";
    else cout<<"no\n";

}

int main() {
    int t = 1;
//    freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
    allam
    cin >> t;
    while (t--) {
        solve();
    }

}
