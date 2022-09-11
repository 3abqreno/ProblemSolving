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

vector<int> prime(100000+10,1);//the highest prime that i want to go to
void sieve(ll n) {
    for (ll p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p+p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    sieve(n);
    int temp;
    for (int i = 2; i < n; ++i) {
        if(prime[i]==1) {
            temp = i * i;
            while (temp <= (n)) {
                prime[temp] = 2;
                temp *= i;
            }
        }
    }
    ll s=0;
    vector<int>v;
    for (int i = 2; i <= n; ++i) {
        if(prime[i]){
            s++;
            v.push_back(i);
        }
    }
    cout<<s<<'\n';
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<" ";
    }
}

int main() {
    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    allam
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}
