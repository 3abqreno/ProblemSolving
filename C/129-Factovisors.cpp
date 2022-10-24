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
    int n, m;
    while (cin >> n >> m) {
        cout << m;
        if (n == 0 || n == 1) {
            if (m == 1) cout << " divides " << n << "!\n";
            else cout << " does not divide " << n << "!\n";
            continue;
        }
        map<int, int> mp;
        for (int i = 2; i * i <= m; ++i) {
            while (m % i == 0) {
                mp[i]++;
                m /= i;
            }
        }
        if (m > 1)mp[m]++;
        bool ok = 1;
        for (auto i: mp) {
            int cnt = 0;
            for (int j = i.first; j <= n; j += i.first) {
                int temp = j;
                while (temp % i.first == 0) {
                    cnt++;
                    temp /= i.first;
                }
                if (cnt >= i.second)break;
            }
            if (cnt < i.second) {
                ok = 0;
                break;
            }
        }
        if (ok)
            cout << " divides " << n << "!\n";
        else
            cout << " does not divide " << n << "!\n";
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
