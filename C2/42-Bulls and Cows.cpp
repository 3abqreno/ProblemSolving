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

pair<int, int> check(string a, string b) {
    if(b.size()==3)b="0"+b;
    set<char> s;
    int bull = 0, cow = 0;
    for (auto i: a)s.insert(i);
    for (int i = 0; i < 4; ++i) {
        if (a[i] == b[i])bull++;
        else if (s.find(b[i]) != s.end())cow++;
    }
    return {bull, cow};
}

void solve() {
    vector<string> v;
    for (int i = 100; i < 10001; ++i) {
        string s = to_string(i);
        if (s.size() < 4)s = '0' + s;
        bool seen[10] = {};
        bool add = 1;
        for (auto i: s)
            if (!seen[i - '0'])seen[i - '0'] = 1;
            else {
                add = 0;
                break;
            };
        if (add)v.push_back(s);
    }
    int n;
    cin >> n;
    vector<int> pred(v.size());
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = 0; j < v.size(); ++j) {
            pair<int, int> p = check(v[j], to_string(a));
            if (p.first == b && p.second == c){
                pred[j]++;
            }
        }
    }
    int index = -1;
    for (int i = 0; i < pred.size(); ++i) {
        if (pred[i] == n) {
            if (index != -1)return void(cout << "Need more data");
            index = i;
        }
    }
    cout <<((index==-1)? "Incorrect data":v[index]);

}


int main() {
    int t = 1;
    //   freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
    }

}
