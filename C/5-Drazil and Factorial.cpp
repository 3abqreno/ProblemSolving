
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


void solve() {
    int n,c;
    cin>>n;
    string x;
    cin>>x;
    vector<int>num;
    for (int i = 0; i < n; ++i) {
    if(x[i]=='6'){
            num.push_back(3);
            num.push_back(5);
    }
    else if(x[i]=='4'){
        num.push_back(3);
        num.push_back(2);
        num.push_back(2);
    }
    else if(x[i]=='8'){
        num.push_back(7);
        num.push_back(2);
        num.push_back(2);
        num.push_back(2);
    }
    else if(x[i]=='9'){
        num.push_back(7);
        num.push_back(3);
        num.push_back(3);
        num.push_back(2);
    }
    else if((x[i]-'0')>1)num.push_back(x[i]-'0');

    }
    sort(num.rbegin(),num.rend());
    for (int i = 0; i < num.size(); ++i) {
        cout<<num[i];
    }
    if(num.size()==0)cout<<1;
}


int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    allam
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

}
