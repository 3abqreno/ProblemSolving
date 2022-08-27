
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


void solve() {
    ll n, d;
    cin>>n>>d;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        cin >> v[i].second;
    }
    sortv(v);
    vector<ll>m(n);
    m[0]=v[0].second;
    for (int i = 1; i < n; ++i) {
        m[i]=v[i].second;
        v[i].second += v[i - 1].second;
    }
    ll f = 0, s = 0, mx = 0;
    for (int i = 0; i < n; ++i) {
        while (v[s].first - v[f].first >= d) {
            if ((s - f) == 1) {
                mx=max(mx,m[f]);
            }
            else {
                if (f > 0)
                    mx = max(mx, v[s - 1].second - v[f - 1].second);
                else
                    mx=max(mx,v[s-1].second);
            }
        f++;
        }
        s++;
    }
    if (v[s-1].first - v[f].first < d) {
        if ((s - f) == 1) {
            mx=max(mx,m[f]);
        }
        else if(f==0)mx=max(mx,v[s-1].second);
        else
            mx = max(mx,v[s - 1].second - v[f-1].second);
    }
    cout<<mx;

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
