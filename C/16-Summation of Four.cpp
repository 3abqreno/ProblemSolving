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

bool prime[10000010];

void sieve(ll n) {
    for (ll p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

void solve() {
    memset(prime, 1, 10000000);
    sieve(10000010);
    map<ll, bool> pr;
    pr[2] = 1;
    for (int i = 3; i < 10000010; i += 2) {
        if (prime[i])pr[i] = 1;
    }
    ll n;
    int a = 2;
    while (cin >> n) {
        if (n > 7) {
            if (n % 2 == 0) {
                cout << "2 2 ";
                for (auto i: pr) {
                    if (pr.find(n - 4 - i.first) != pr.end()) {
                        cout << i.first << " " << n - 4 - i.first << endl;
                        break;
                    }
                }
            }
            else{
                cout << "2 3 ";
                for (auto i: pr) {
                    if (pr.find(n - 5 - i.first) != pr.end()) {
                        cout << i.first << " " << n - 5 - i.first << endl;
                        break;
                    }
                }
            }
        } else {
            cout << "Impossible." << endl;
        }

    }


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
