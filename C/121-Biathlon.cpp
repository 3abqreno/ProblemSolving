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

struct circle {
    ll x, r, index, ans;

    circle() {
        ans = INT_MAX;
    }

    bool operator<(circle other) {
        return this->x < other.x;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<circle> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].x >> v[i].r;
        v[i].index = i;
    }
    sortv(v);
    int m;
    cin >> m;
    vector<pair<ll, pair<ll, int>>> p(m);
    for (int i = 0; i < m; ++i) {
        cin >> p[i].first >> p[i].second.first;
        p[i].second.second = i + 1;
    }
    sortv(p);
    int index = 0;
    for (int i = 0; i < m; ++i) {
        int x = p[i].first, y = p[i].second.first;
        while (x > (v[index].x + v[index].r))index++;
        if (((x - v[index].x) * (x - v[index].x) + y * y) <= v[index].r * v[index].r) {
            v[index].ans = min(p[i].second.second, int(v[index].ans));
        }
        if (index < n - 1 && ((x - v[index + 1].x) * (x - v[index + 1].x) + y * y) <= v[index + 1].r * v[index + 1].r){
            v[index+1].ans = min(p[i].second.second, int(v[index+1].ans));
        }
    }


    vector<int> ans(n);
    int cnt = 0;
    for (
            int i = 0;
            i < n;
            ++i) {
        ans[v[i].index] = v[i].
                ans;
        if (v[i].ans != INT_MAX)cnt++;
    }
    cout << cnt << '\n';
    for (
            int i = 0;
            i < n;
            ++i) {
        cout << (ans[i] == INT_MAX ? -1 : ans[i]) << " ";
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
