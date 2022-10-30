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
bool vis[102][100005] = {};

void solve() {
    int n;
    cin >> n;
    int v[120];
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        v[i]++;
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    queue<pair<int, pair<int, int>>> q;
    q.push({b, {a, 0}});
    while (!q.empty()) {
        b = q.front().first, a = q.front().second.first;
        int dis = q.front().second.second;
        if (b == d && c == a) {
            cout << dis;
            return;
        }
        if (b + 1 <= v[a] && !vis[a][b + 1]) {
            vis[a][b + 1] = 1;
            q.push({b + 1, {a, dis + 1}});
        }
        if (b - 1 >= 1 && !vis[a][b - 1]) {
            vis[a][b - 1] = 1;
            q.push({b - 1, {a, dis + 1}});
        }
        if (a + 1 <= n && !vis[a + 1][min(b, v[a + 1])]) {

            vis[a + 1][min(b, v[a + 1])] = 1;
            q.push({min(b, v[a + 1]), {a + 1, dis + 1}});
        }
        if (a - 1 >= 1 && !vis[a - 1][min(b, v[a - 1])]) {
            vis[a - 1][min(b, v[a - 1])] = 1;
            q.push({min(b, v[a - 1]), {a - 1, dis + 1}});
        }
        q.pop();
    }
}


int main() {
    int t = 1;
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
    }

}
