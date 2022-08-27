
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
#define fast  ios_base::sync_with_stdio(false);cin.tie(nullptr);
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

double nCr(double n, double r) {
    int i, res;
    if (r > 0)
        return (n / r) * nCr(n - 1, r - 1);
    else
        return 1;
}


void solve() {
    int n,x,y;
    cin>>n;
    ll sum=0;
    map<int,ll>m1;
    map<int,ll>m2;
    int ans=0;
    for (int i = 0; i < n; ++i)
    {
        int x,y;
        cin>>x>>y;

        sum+=m1[x+y]++;
        sum+=m2[x-y]++;
    }
    cout<<sum;
}


int main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt", "w", stdout);
    fast
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

}
