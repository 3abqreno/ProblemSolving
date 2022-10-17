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
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};


void solve() {
    ll n;
    while (cin >> n) {
        if (!n)return;
        map<int, int> mp;
        ll s=abs(n);
        for (ll i = 2; i * i <= s   ; ++i) {
            while (s % i == 0) {
                mp[i]++;
                s /= i;
            }
        }
        if (s > 1)mp[s]++;
        int ans =mp.begin()->second;
        for (auto i: mp)ans = __gcd(ans,i.second);

        while(n<0&&!(ans&1)){
            ans>>=1;
        }
        cout<<ans<<'\n';
    }


}

int main() {
    int t = 1;
    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
    }

}
