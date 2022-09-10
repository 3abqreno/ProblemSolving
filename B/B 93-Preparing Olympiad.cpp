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

int binarySearch(vector<ll> v, int To_Find) {
    int lo = 0, hi = v.size() - 1;
    int mid;
    // This below check covers all cases , so need to check
    // for mid=lo-(hi-lo)/2
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if (v[mid] < To_Find) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    if (v[lo] == To_Find) {
        return lo;
    } else if (v[hi] == To_Find) {
        return hi;
    } else {
        return -1;
    }
}

ll n, l, r, x;
vector<ll> v;

ll f(ll index, ll s, ll lowest,ll h) {
    ll ans = 0;
    if (index <n-1) {
        if ((v[index + 1] + s) <= r) {
            ans += f(index + 1, s + v[index + 1], lowest,index+1);
        }
        ans += f(index+1, s, lowest,h);
    }
    if ((s >= l) && (s <= r) ) {
        if(index==h&&(v[h] - lowest) >= x)
        ans++;
    }
    return ans;
}

void solve() {

    cin >> n >> l >> r >> x;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sortv(v);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += f(i, v[i], v[i],-1);
    }
    cout << ans;
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
