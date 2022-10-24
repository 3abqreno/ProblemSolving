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

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};


void solve() {
    string word;
    cin >> word;
    ll b = 0, s = 0, c = 0;
    for (ll i = 0; i < word.size(); ++i) {
        if (word[i] == 'B')b++;
        else if (word[i] == 'S')s++;
        else c++;
    }
    ll q, w, e, pb, ps, pc, r;
    cin >> q >> w >> e >> pb >> ps >> pc >> r;
    ll sand = 0;
    ll bu = 0, mb, ms, mc;
    if (b > 0)
        sand = q / b;
    if(s>0)
        sand=min(sand,w/s);
    if(c>0)
        sand=min(sand,e/c);

    q -= sand * b;
    w -= sand * s;
    e -= sand * c;
    while ((q>0&&b) || (w>0&&s) || (e>0&&c)) {
        if (q < b) {
            r -= (b - q) * pb;
            q = b;
        }
        if (w < s) {
            r -= (s - w) * ps;
            w = s;
        }
        if (e < c) {
            r -= (c - e) * pc;
            e = c;
        }
        if (r < 0)break;
        sand++;
        q -= b;
        w -= s;
        e -= c;
    }
    cout << sand + r / (b * pb + s * ps + c * pc);


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
