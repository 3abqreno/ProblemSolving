//   _____       _
//  |____ |     | |
//     / / __ _| |__   __ _ _ __ ___ _ __   ___
//      \ \/ _` | '_ \ / _` | '__/ _ \ '_ \ / _ \
        //  .___/ / (_| | |_) | (_| | | |  __/ | | | (_) |
//  \____/ \__,_|_.__/ \__, |_|  \___|_| |_|\___/
//                       | |
//                       |_|
#include<iostream>
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//
//using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set_ll tree<ll, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<ll , null_type ,  less_equal<ll> , rb_tree_tag , tree_order_statistics_node_update>
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
#define F first
#define S second
using namespace std;
typedef long long ll;
const double pi = 3.14159265358979323846;
#define MOD 1000000007
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);


long long gcd(ll a, ll b) {
    if (b == 0)
        return a;
    if (a == 0)
        return b;
    return gcd(b, a % b) % MOD;
}

long long lcm(int a, int b) {
    if (a == 1 && b == 1) {
        return 1;
    }
    return (a / gcd(a, b)) * b;
}


long long fast_power(long long base, long long power) {
    long long result = 1;
    while (power > 0) {

        if (power % 2 == 1) {
            result = (result * base);
        }
        base = (base * base) ;
        power >>= 1;
    }
    return result ;
}
ll m, n;

int dx[8] = {0, 0, 1, -1};
int dy[8] = {1, -1, 0, 0};
char s1[int(1e5 + 1)], s2[int(1e5 + 1)];

void solve() {
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> s1[i];
    }
    int diff = 0,same=0;
    for (int i = 0; i < n; ++i) {
        cin >> s2[i];
        if (s1[i] != s2[i])diff++;
        else same++;
    }
    if ((same+(diff/2))<(n-t)) {
        cout << -1;
        return;
    }
    int flip=0,change=0;
    if(same<(n-t)){
        flip=(n-t-same)*2;
    }else if(same>(n-t)){
        change=same-n+t;
    }
    bool one = 1;
    for (int i = 0; i < n; ++i) {
        if (s1[i] == s2[i]) {
          if(change){
              char c='a';
              for (int j = 0; j < 26; ++j) {
                  if((c+j)!=s1[i]&&(c+j)!=s2[i]){
                      c+=j;
                      cout<<c;
                  break;
                  }

              }
              change--;
          }else cout<<s1[i];
        } else {
           if(flip){
               if(one)cout<<s1[i];
               else cout<<s2[i];
               one=!one;
               flip--;
           }
           else{
               char c='a';
               for (int j = 0; j < 26; ++j) {
                   if((c+j)!=s1[i]&&(c+j)!=s2[i]){
                       c+=j;
                       cout<<c;
                       break;
                   }

               }
           }
        }
    }


}


int main() {

//    freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
    allam
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }

}
