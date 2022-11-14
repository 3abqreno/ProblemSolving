//   _____       _
//  |____ |     | |
//      / / __ _| |__   __ _ _ __ ___ _ __   ___
//      \ \/ _` | '_ \ / _` | '__/ _ \ '_ \ / _ \
    //  .___/ / (_| | |_) | (_| | | |  __/ | | | (_) |
//  \____/ \__,_|_.__/ \__, |_|  \___|_| |_|\___/
//                       | |
//                       |_|
#include <bits/stdc++.h>

#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};


void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i: v)cin >> i;
    int g = v[0], mx = v[0];
    for (int i = 1; i < n; ++i) {
        g = gcd(g, v[i]);
        mx = max(mx, v[i]);
    }
  cout<<(((mx /g ) -n) % 2 == 0?"Bob":"Alice");


}

int main() {
    int t = 1;
    //    freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
    allam
    //    cin >> t;
    while (t--) {
        solve();
    }

}
