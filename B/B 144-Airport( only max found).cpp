
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
int dx[8] = {0, 0, 1, -1};
int dy[8] = {1, -1, 0, 0};

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
        return b * fastpow(b, e - 1);
    }
    ll x = fastpow(b, e / 2);
    return x * x;
}

void solve() {
    int n, m,k=0;
    cin >> n>> m;
    vector<int> air(m);
    for (int i = 0; i < m; ++i) {
        cin >> air[i];
        k+=air[i];
    }
    ll sum = 0, index = 0;
    sort(air.rbegin(), air.rend());
    while (n&&k) {
        if (air[index] >= air[((index + 1) % m)] && air[index] != 0) {
            sum += air[index];
            air[index]--;
            n--;
            k--;
        } else {
            index = (index + 1) % m;

        }
    }
    cout << sum;
}


int main() {
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    allam
    int t = 1;
    //   cin >> t;
    while (t--) {
        solve();
    }

}
