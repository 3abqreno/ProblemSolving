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


long long gcd(int a, int b) {
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

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int m = INT_MAX;
vector<ll> countDivisors(ll n,bool &ok) {
    ok=1;
    vector<ll>div;
    for (ll i = 2; i*i <=n ; i++) {
        if (n % i == 0) {
            if (n / i == i) {
                div.push_back(i);
                ok=0;
            }
            else
            {
            div.push_back(i);
            div.push_back(n/i);
            ll sqr= sqrt(i);
            if(sqr*sqr==i)
                ok=0;
            sqr=sqrt(n/i);
            if(sqr*sqr==(n/i))
                ok=0;
            }
        }
    }
    return div;
}
map<ll,bool>check;
ll f(ll n){
    check[n]=1;
    vector<ll>div;
    bool ok=0;
    div=countDivisors(n,ok);
    if(ok)return n;
    ll m=1;
    for(auto i: div){
        if(!check[i])
        m=max(m,f(i));
    }
    return m;
}

void solve() {
    ll n;
    cin>>n;
    cout<<f(n);
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
