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
int pre[int(2e5 + 5)]={};

void solve() {
    int k, n, q;
    cin >> n >> k >> q;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        pre[l]++;
        pre[r + 1]--;
    }
    for (int i = 1; i < 2e5 + 5; ++i) {
        pre[i] += pre[i - 1];
    }
    for (int i = 1; i < 2e5+5; ++i) {
        pre[i]=pre[i]>=k;
        pre[i]+=pre[i-1];
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << pre[b] - pre[a - 1] << '\n';
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