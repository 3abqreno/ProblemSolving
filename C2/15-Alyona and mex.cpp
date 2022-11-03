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
#define MOD 1000000007
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

void solve() {
    int n,m,mn=INT_MAX;
    cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        int l,r;cin>>l>>r;
        mn=min(mn,r-l);
    }
    mn++;
    cout<<mn<<'\n';
    int loop=n/mn;
    for (int i = 0; i <loop ; ++i) {
        for (int j = 0; j < mn; ++j) {
            cout<<j<<" ";
        }
    }
     loop=n%mn;
    for (int i = 0; i < loop; ++i) {
        cout<<i<<" ";
    }

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
