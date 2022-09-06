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

long long lcm(int a, int b) {
    if (a == 1 && b == 1) {
        return 1;
    }
    return (a / gcd(a, b)) * b;
}

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
vector<ll> factors(5);

ll f(ll n, ll index, ll num, ll op = 1) {
    ll s = n / num * op;
    if (num > n)return s;
    for (ll i = index + 1; i < 5; ++i) {
        s += f(n,i, lcm(num, factors[i]), -op);
    }
    return s;
}


void solve() {
    factors.resize(5);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = 0; i < 5; ++i) {
        factors[i] = c + d * i;
    }

    ll sa = 0, sb = 0;
    for (ll i = 0; i < 5; ++i) {
        sa += f(a-1, i, factors[i], 1);
    }
    for (ll i = 0; i < 5; ++i) {
        sb += f(b, i, factors[i], 1);
    }
    cout << b-a-(sb - sa)+1<<endl;
    factors.clear();
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", std   out);
    //allam
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

}
