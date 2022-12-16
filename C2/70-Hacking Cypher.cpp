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
//using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set_ll tree<ll, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<ll , null_type ,  less_equal<ll> , rb_tree_tag , tree_order_statistics_node_update>
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;
const double pi = 3.14159265358979323846;
#define MOD 1000000007
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1, -1, 0};
int dy[8] = {1, -1, 0, 0, 0};


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

int MAX = 1e6 + 10;
int p[int(1e6 + 10)];
int p2[int(1e6 + 10)];
int l[int(1e6 + 10)];
int r[int(1e6 + 10)];

void solve() {
    string s;
    cin >> s;
    int a, b, k = 1;
    p[0] = 1;
    p2[0] = 1;
    cin >> a >> b;
    for (int i = 1; i <= 1e6; ++i) {
        k *= 10;
        k%=a;
        p[i] = k;
    }
    k = 1;
    for (int i = 1; i <= 1e6; ++i) {
        k *= 10;
        k%=b;
        p2[i] = k;
    }
    int x = 0, y = 0, sz = s.size();
    for (int i = 0; i < sz; ++i) {
        x = (x*10 + (s[i]-'0')) % a;
        l[i]=x;
        y = (y + (s[sz-i-1]-'0')*p2[i]) % b;
        if(s[sz-i-1]-'0')
        r[sz-i-1] = y;
        else r[sz-i-1]=-1;
    }
    for (int i = 0; i < s.size()-1; ++i) {
        if (!l[i] && !r[i + 1]) {
            cout << "YES\n";
            cout<<s.substr(0,i+1)<<'\n';
            cout<<s.substr(i+1,sz-(i+1));
            return;
        }
    }

    cout << "NO";

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
