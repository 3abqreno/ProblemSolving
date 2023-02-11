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
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
typedef long long ll ;

int a[int(2e5+5)];
#define X first
#define Y second
vector<pair<int,int>>seg;
set<pair<int,int>>s;
set<int>ind;
void solve() {
    int n;
    cin >> n;
    if (n == 1)return void(cout << 1);
    int in = 0, prev;
    cin >> a[0];
    prev = a[0];
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        if (a[i] != prev) {
            s.insert({i - in, seg.size()});
            ind.insert(seg.size());
            seg.push_back({prev, i - in});
            in = i;
        }
        prev = a[i];
    }
    ind.insert(seg.size());
    s.insert({n - in, seg.size()});
    seg.push_back({prev, n - in});
    int ans = 0;
    while (s.size()) {
        ans++;
        int sz = s.rbegin()->first;
        auto it2=s.lower_bound({sz, 0});
        auto it = ind.find(it2->second);

        if (it == ind.begin() || it == --ind.end()) {
            s.erase(s.lower_bound({sz, 0}));
            ind.erase(it);
            continue;
        }
        auto l = --it, r = ++ind.find(it2->second);
        if(seg[*l].first==seg[*r].first){
            s.erase({seg[*l].second,*l});
            s.erase({seg[*r].second,*r});
            s.insert({seg[*r].second+seg[*l].second,*l});
            seg[*l].second+=seg[*r].second;
            ind.erase(*r);
        }
        s.erase(it2);
        ++it;
        ind.erase(it);
    }
        cout << ans;
}
int main() {
    int t = 1;
//       freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }

}
