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
    bool z = 0;
    string s;
    cin >> s;
    vector<char> v;
    for (int i = 0; i < s.size(); ++i) {
        if (!z && s[i] == '2'){
            z = 1;
                sort(s.begin(),s.begin()+i+1);
                cout<<s.substr(0,i);
        }
        if(z) {
            if ((s[i] == '2' || s[i] == '0')) {
                v.push_back(s[i]);
            } else cout << s[i];
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i];
    }
    if(!z){
        sortv(s);
        cout<<s;
    }


}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", std   out);
    // allam
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

}
