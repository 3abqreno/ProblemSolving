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

bool prime[int(2e6+1)]={};
bool notPalin[int(2e6+1)]={};
void sieve(){
    for (int i = 2; i < 2000001; ++i) {
        if(!prime[i]){
            for (int j = i+i; j <2000001; j+=i) {
                prime[j]=1;
            }
        }
    }
}
void computePalin(){
    for (int i = 1; i < 2000001; ++i) {
        string s=to_string(i);
        for (int j = 0; j < s.size()/2; ++j) {
            if(s[j]!=s[s.size()-1-j]){
                notPalin[i]=1;
                break;

            }
        }
    }
}
void solve() {
    sieve();
    computePalin();

  int p,q,ans=1;cin>>p>>q;
    int cPrime=0,cPalin=1;
    for (int i = 2; i < 2e6; ++i) {
        cPrime+=!prime[i];
        cPalin+=!notPalin[i];
        if(q*cPrime<=(p*cPalin)){
           ans=i;
        }
    }
    cout<<ans;
//    cout <<cPrime<<" "<<cPalin;
}


int main() {
    int t = 1;
    //   freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }

}
