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
//#include <ext/pb_ds/assoc_container.hpp>
//
//using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set_ll tree<ll, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<ll , null_type ,  less_equal<ll> , rb_tree_tag , tree_order_statistics_node_update>
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
#define F first
#define S second
using namespace std;
typedef long long ll;
const double pi = 3.14159265358979323846;
#define MOD 1000000007
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);


long long gcd(ll a, ll b) {
    if (b == 0)
        return a;
    if (a == 0)
        return b;
    return gcd(b, a % b) % MOD;
}

long long lcm(int a, int b) {
    if (a == 1 && b == 1) {
        return 1;
    }
    return (a / gcd(a, b)) * b;
}


long long fast_power(long long base, long long power) {
    long long result = 1;
    while (power > 0) {

        if (power % 2 == 1) {
            result = (result * base);
        }
        base = (base * base);
        power >>= 1;
    }
    return result;
}

int dx[8] = {0, 0, 1, -1};
int dy[8] = {1, -1, 0, 0};

struct node {
    string s;
    int a;

    node() {}

    node(string ss, int aa) {
        s = ss;
        a = aa;
    }

    bool operator<(node other) {
        if (this->a > other.a)return 1;
        else if (this->a < other.a)return 0;
        else {
            return this->s < other.s;
        }
    }
};

void solve() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; ++i) {
        string a, b, action, c;
        cin >> a >> action;
        if (action == "posted" || action == "commented") {
            cin >> b >> b;
            cin >> c;
        } else {
            cin >> b;
            cin >> c;
        }
        if (a == s || b.substr(0, b.size() - 2) == s) {
            if (a != s){
                swap(a, b);
            }else b=b.substr(0,b.size()-2);
            if (action == "posted")mp[b] += 15;
            else if (action == "commented")mp[b] += 10;
            else mp[b] += 5;
        }
        else{
            mp[a];
            mp[b.substr(0,b.size()-2)];
        }
    }
    vector<node> v;
    for (auto i: mp) {
        v.push_back(node(i.first, i.second));
    }
    sortv(v);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].s << '\n';
    }
}


int main() {

//    freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
    allam
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }

}
