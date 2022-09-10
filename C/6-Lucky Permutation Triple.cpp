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


ll fastpow(ll b, ll e) {
    ll temp;
    if (!e) {
        return 1;
    }
    if (e & 1) {
        temp = (__int128) b * fastpow(b, e - 1) % MOD;
        return temp;
    }
    ll x = fastpow(b, e / 2) % MOD;
    temp = (__int128) x * x % MOD;
    return temp;
}

int dx[8] = {0, 0, 1, -1};
int dy[8] = {1, -1, 0, 0};

void solve() {
    int n, a, b, c;
    cin >> n;
    a = 1 % n;
    b = 2 % n;
    c = (a + b) % n;
    vector<vector<int>> v(3, vector<int>(n));
    if(n%2==0){
        cout<<-1;
        return;
    }
    for (int i = 0; i < n; ++i) {
        v[0][i] = a;
        v[1][i] = b;
        v[2][i] = c;
        a = (a + 2) % n;
        b = (b + 2) % n;
        c = (a + b) % n;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", std   out);
    allam
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}
