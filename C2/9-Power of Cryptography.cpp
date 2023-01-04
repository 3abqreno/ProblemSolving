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

#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
//typedef tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int n;
vector<int> num(220);

bool check(vector<int> &v) {
    vector<int> temp(220);
    vector<int> out(220);
    temp = out = v;
    for (int i = 0; i < n - 1; ++i) {
        out.assign(220, 0);
        for (int j = 0; j <= 12; ++j) {
            for (int k = 0; k <= 120; ++k) {
                out[j + k] += v[j] * temp[k];
            }
        }
        for (int j = 0; j <= 150; ++j) {
            out[j + 1] += out[j] / 10;
            out[j] %= 10;
        }
        temp = out;
    }
    for (int i = 200; i >= 0; i--) {
        if (num[i] != out[i]) {
            return out[i] < num[i];
        }
    }
    return true;
}

void solve() {

    string s;
    while (cin >> n >> s) {
        num.assign(220,0);
        if(n==0&&s=="0")return;
        for (int i = 0; i < s.size(); ++i) {
            num[i] = s[s.size() - i - 1] - '0';
        }
        int l = 1, r = 1e9 + 10, ans;
        while (l <= r) {
            int md = (l + r) / 2;
            if (log10(md) * n >120) {
                r = md - 1;
                continue;
            }
            vector<int> v(13, 0);
            string s2 = to_string(md);
            for (int i = 0; i < s2.size(); ++i) {
                v[i] = s2[s2.size() - i - 1] - '0';
            }
            if (check(v)) {
                ans = md;
                l = md + 1;
            } else {
                r = md - 1;
            }
        }
        cout << ans << '\n';
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
