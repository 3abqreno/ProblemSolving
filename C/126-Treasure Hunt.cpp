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
//using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set_ll tree<ll, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<ll , null_type ,  less_equal<ll> , rb_tree_tag , tree_order_statistics_node_update>
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
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
        base = (base * base);
        power >>= 1;
    }
    return result;
}

int dx[8] = {0, 0, 1, -1, 0};
int dy[8] = {1, -1, 0, 0, 0};



void solve() {
ll n;
string a,b,c;
cin>>n>>a>>b>>c;
    map<char,int>mpa;
    map<char,int>mpb;
    map<char,int>mpc;
    for (int i = 0; i <a.size(); ++i) {
        mpa[a[i]]++;
    }
    for (int i = 0; i <b.size(); ++i) {
        mpb[b[i]]++;
    }
    for (int i = 0; i <c.size(); ++i) {
        mpc[c[i]]++;
    }
    ll ca=0,cb=0,cc=0;
    for(auto i:mpa)if(i.second>ca)ca=i.second;
    for(auto i:mpb)if(i.second>cb)cb=i.second;
    for(auto i:mpc)if(i.second>cc)cc=i.second;
  if(ca==a.size()){
      ca=a.size()-((n-(a.size()-ca))==1);
  }else ca=min(ca+n,ll(a.size()));

    if(cb==a.size()){
        cb=a.size()-((n-(a.size()-cb))==1);
    }else cb=min(cb+n,ll(a.size()));

    if(cc==c.size()){
        cc=a.size()-((n-(a.size()-cc))==1);
    }else cc=min(cc+n,ll(a.size()));
    if((ca==cb&&ca>cc)||(ca==cc&&ca>cb)||(cb==cc&&cb>ca)||(ca==cb&&ca==cc)){
        cout<<"Draw";
    }
    else if(ca>cb&&ca>cc)cout<<"Kuro";
    else if(cb>ca&&cb>cc)cout<<"Shiro";
    else cout<<"Katie";
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
