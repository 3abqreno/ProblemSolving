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

struct piece {
    ll c, q;

    piece() {}

    piece(ll _c, ll _q) {
        c = _c;
        q = _q;
    }

    bool operator<(const piece other) const {
        if (c != other.c)return c < other.c;
        else return q < other.q;
    }
};

void solve() {
    ll n, b;
    cin >> n >> b;
    map<string, int> mp;
    int idx = 0;
    vector<priority_queue<piece>> v;
    for (int i = 0; i < n; ++i) {
        string s, t;
        cin >> s >> t;
        ll c, q;
        cin >> c >> q;
        if (mp.find(s) == mp.end())mp[s] = idx++, v.push_back(priority_queue<piece>());
        v[mp[s]].push(piece(-c, -q));
    }
    ll q = 1e18, mn = 0;
    vector<pair<ll, ll>> quality(v.size());
    for (int i = 0; i < v.size(); ++i) {
        b += v[i].top().c;
        if (q > -v[i].top().q) {
            q = -v[i].top().q;
            mn = i;
        }
        quality[i].first = -v[i].top().q;
        quality[i].second = -v[i].top().c;
        v[i].pop();
    }
    while (!v[mn].empty()) {

        while (!v[mn].empty() && -v[mn].top().q < quality[mn].first) {
            v[mn].pop();
            continue;
        }
        if ((-v[mn].top().c - quality[mn].second) > b)break;

        if (v[mn].empty())break;
        b += v[mn].top().c + quality[mn].second;
        quality[mn].first = -v[mn].top().q;
        quality[mn].second = -v[mn].top().c;
        v[mn].pop();
        ll temp = 1e18;
        for (int i = 0; i < quality.size(); ++i) {
            if (quality[i].first < temp) {
                temp = quality[i].first;
                mn = i;
            }
        }
        q = max(q, temp);
    }
    cout << q << '\n';

}


int main() {
    int t = 1;
    //   freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
    allam
    cin >> t;
    while (t--) {
        solve();
    }

}
