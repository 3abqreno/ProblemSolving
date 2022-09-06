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
#include<cmath>
#include <unordered_map>
 
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
    return gcd(b, a % b);
}
 
ll fastpow(ll b, ll e) {
    if (!e) {
        return 1;
    }
    if (e & 1) {
        return b * fastpow(b, e - 1) % MOD;
    }
    ll x = fastpow(b, e / 2) % MOD;
    return x * x % MOD;
}
double nCr(double n, double r) {
    ll i, res;
    if (r > 0)
        return (n / r) * nCr(n - 1, r - 1);
    else
        return 1;
}
 
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
ll f(ll a,ll end){
    ll o=1;
    while(end){
        o*=a;
        a--;
        end--;
    }
    return o;
}
long long C(ll n, ll r) {
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    ll i;
 
    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }
 
    return ans;
}
void solve() {
    ll n,m,t,sum=0,a,b;
    cin>>n>>m>>t;
    ll en=min(t-1,n);
    for (ll i = 4; i <= en; ++i) {
        if(i+m>=t){
            a=C(n,i);
            b=C(m,t-i);
            sum+=a*b;
        }
    }
    cout<<sum;
 
}
 
int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", std   out);
    allam
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
 
}
