//   _____       _
//  |____ |     | |
//      / / __ _| |__   __ _ _ __ ___ _ __   ___
//      \ \/ _` | '_ \ / _` | '__/ _ \ '_ \ / _ \
//  .___/ / (_| | |_) | (_| | | |  __/ | | | (_) |
//  \____/ \__,_|_.__/ \__, |_|  \___|_| |_|\___/
//                       | |
//                       |_|
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
bool prime[4005] = {};
vector<int> p;
void sieve(int n) {
    for (int i = 2; i < n; ++i) {
        if (prime[i])continue;
        for (int j = i + i; j < n; j += i) {
            prime[j] = 1;
        }
        p.push_back(i);
    }

}

void solve() {
    sieve(3900);
    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v[0];
    int g = v[0];
    bool diff = 0;
    for (int i = 1; i < n; ++i) {
        cin >> v[i];
        diff |= (v[i] != v[i - 1]);
        if (g > 1)
            g = __gcd(g, v[i]);
    }
    if (!diff)return void(cout << -1);

    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        v[i] /= g;
        if(v[i]==1)continue;
        for (auto j: p) {
            if (v[i] % j == 0){
                while(v[i]%j==0)v[i]/=j;
                mp[j]++;
            }
        }
        if(v[i]>1)mp[v[i]]++;
    }
    int ans = 0;
    for (auto i: mp)ans = max(ans, i.second);
    cout << n - ans;


}


int main() {
    int t = 1;
    //   freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }

}
