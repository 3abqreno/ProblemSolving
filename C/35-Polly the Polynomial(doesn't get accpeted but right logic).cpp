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


long long fast_power(long long base, long long power) {
    long long result = 1;
    while (power > 0) {

        if (power % 2 == 1) {
            result = (result * base);
        }
        base = (base * base);
        power >>= 1;
    }
    return result;
}

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int f=0;
void solve() {
    string c, x;
    ll a;
    while (getline(cin, c)) {
        if(f)cout<<"\n";
        f++;
        if (c == "")break;
        getline(cin, x);
        vector<ll> cons;
        ll sz = c.size(), prev = 0;
        stringstream s;
        s << c;
        while (s >> a) {
            cons.push_back(a);
        }
        ll sz2 = x.size(), n;
        prev = 0;
        s.clear();
        s << x;
        ll sum=0;
        while(s>>a){
            cout<<" ";
            sum=0;
            for (int i = 1; i <= cons.size(); ++i) {
                sum+= fast_power(a,cons.size()-i)*cons[i-1];
            }
        cout<<sum;
        }
    }

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
