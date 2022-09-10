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


void solve() {
    string s;
    cin >> s;
    vector<int> v(s.size());
    ll sz = s.size();
    for (int i = 0; i < sz; ++i) {
        v[i] = s[i] - '0';
    }
    ll temp;
    for (int i = 0; i < sz; ++i) {
        if(v[i]==8||v[i]==0){
            cout << "YES" << endl << v[i];
            return;
        }
        for (int j = i + 1; j < sz; ++j) {
            temp = (v[i] * 10 + v[j]);
            if (temp % 8 == 0) {
                cout << "YES" << endl << temp;
                return;
            }
            for (int k = j + 1; k < sz; ++k) {
                temp = (v[i] * 100 + v[j] * 10 + v[k]);
                if (temp % 8 == 0) {
                    cout << "YES" << endl << temp;
                    return;
                }
            }
        }

    }
    cout << "NO";


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
