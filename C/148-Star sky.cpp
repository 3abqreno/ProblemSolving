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
int sum[105][105][15] = {};
int s[105][105][15] = {};
int ax[100005], ay[100005], at[100005];

void solve() {
    int n, q, c;
    cin >> n>>q>>c;
    for (int i = 0; i < n; ++i) {
        cin >> ax[i] >> ay[i] >> at[i];
    }
    c++;
    for (int t = 0; t < c; ++t) {
        for (int i = 0; i < n; ++i) {
            s[ax[i]][ay[i]][t] += (at[i] + t) % c;
        }
    }
    for (int i = 0; i < c; ++i) {
        for (int j = 1; j < 101; ++j) {
            for (int k = 1; k < 101; ++k) {
                sum[j][k][i] +=s[j][k][i] + sum[j - 1][k][i] + sum[j][k - 1][i] - sum[j - 1][k - 1][i];
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        int t, x1, y1, x2, y2;
        cin >>t>> x1 >> y1 >> x2 >> y2;
        cout<<sum[x2][y2][t%c]+sum[x1-1][y1-1][t%c]-sum[x1-1][y2][t%c]-sum[x2][y1-1][t%c]<<'\n';
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
