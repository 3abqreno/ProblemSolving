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

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int f = 0;

vector<int> prime(100000 + 10, 1);//the highest prime that i want to go to
void sieve(ll n) {
    for (ll p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p + p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
vector<int>v;
bool check( ll n, ll ver){
    if(n%ver != 0) return false;

    ll s = n/ver;

    for(ll i=0;i<s;i++){
        ll might = 1;
        for(ll j=i;j<n;j+=s){
            might &= v[j];
        }

        if(might) return true;
    }

    return false;
}
void solve() {
    int n;
    cin>>n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<ll>prime(1e5 + 10,true);

    for(ll i=2;i*i <= 1e5 + 10;i++){
        if(prime[i]){
            for(ll j=i*i;j<=n;j+=i){
                prime[j] = false;
            }
        }
    }
    for(ll i=3;i<=n;i++){
        if(prime[i] && check( n, i)){
            cout<<"YES"<<endl;
            return ;
        }
    }

    if(check(n,4)){
        cout<<"YES"<<endl;
        return ;
    }

    cout<<"NO"<<endl;

}

int main() {
    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    //allam
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}
