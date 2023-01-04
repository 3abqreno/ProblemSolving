//   _____       _
//  |____ |     | |
//     / / __ _| |__   __ _ _ __ ___ _ __   ___
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
    int a[10][11] = {};
    int n,k;
    ll sum=0;
    cin >>n>>k ;
    for (int i = 0; i < n; ++i) {
        ll b;cin>>b;
        a[b%10][b/10]++;
        sum+=b/10;
    }
    for (int i = 9; i >=0 ; i--) {
        for (int j = 0; j <10 ; j++) {
            int diff=(10-i),bonus=min(k,diff*a[i][j])/diff;
            sum+=bonus;
            a[0][j+1]+=bonus;
            k=max(0,k-a[i][j]*diff);
        }
    }
    cout<<sum;
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
