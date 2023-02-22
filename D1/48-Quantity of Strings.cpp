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
const int mod=1e9+7;
int modPow(ll b,ll p){
    int res=1;
    while(p){
        if(p&1)res=(res*b)%mod;
        b=(b*b)%mod;p>>=1;
    }
    return res;
}

void solve() {
int n,m,k;cin>>n>>m>>k;
if(k>n||k==1)return void(cout<<modPow(m,n));
else if(k==n) return void(cout<<(modPow(m,(n+1)/2)));
else if(!(k&1))return void(cout<<m);
else {
    if(m==1)cout<<1;
    else cout<<m*m%mod;
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
//        if (t)cout << '\n';
    }

}
