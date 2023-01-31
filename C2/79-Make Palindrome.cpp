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
string s;
vector<char> ans, ans2;
int dp[1005][1005];

int go(int i, int j) {
    if (i > j)return 0;
    int &d = dp[i][j];
    if (~d)return d;
    if (s[i] == s[j])d = go(i + 1, j - 1);
    else d = min(go(i + 1, j), go(i, j - 1)) + 1;
    return d;
}

int build(int i, int j) {
    if (i > j)return 0;
    int &d = dp[i][j];
    if (s[i] == s[j]) {
        ans.push_back(s[i]);
        if (i != j) ans2.push_back(s[i]);
        build(i + 1, j - 1);
    } else {
        int c1 = go(i + 1, j) + 1, c2 = go(i, j - 1) + 1, optimal = dp[i][j];
        if (c1 == optimal) {
            ans.push_back(s[i]);
            ans2.push_back(s[i]);
            build(i + 1, j);
        } else {
            ans.push_back(s[j]);
            ans2.push_back(s[j]);
            build(i, j - 1);
        }
    }
    return d;
}

void solve() {
    while (cin >> s&&s!="0") {
        ans.clear();ans2.clear();
        for (int i = 0; i < s.size(); ++i)
            for (int j = 0; j < s.size(); ++j)dp[i][j] = -1;
        cout << go(0, s.size() - 1) << " ";
        build(0, s.size() - 1);
        for (auto i: ans)cout << i;
        reverse(all(ans2));
        for (auto i: ans2)cout << i;
        cout<<'\n';
    }
}

int main() {
    int t = 1;
    //   freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);

    allam
//    cin >> t;
    while (t--) {
        solve();
        if (t)cout << '\n';
    }

}
