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
int row[9] = {};
int col[9] = {};
int diag_r[16+1] = {};
int diag_l[16+1] = {};
int a, b;
vector<vector<int>> out;

void back(int r, vector<int> v) {
    if (row[r]) {
        v[b]=a;
        if(r==8){
            out.push_back(v);
            return;
        }
        back(r + 1, v);
    }
    for (int i = 1; i <= 8; ++i) {
        if (!col[i] && !diag_r[r + i ] && !diag_l[r - i + 8]) {
            col[i] = 1;
            diag_r[r + i ] = 1;
            diag_l[r - i + 8] = 1;
            v[i] = r;
            if (r == 8) {
                out.push_back(v);
            } else {
                back(r + 1, v);
            }
            col[i] = 0;
            diag_r[r + i ] = 0;
            diag_l[r - i + 8] = 0;
            v[i] = 0;
        }
    }
}
int t = 1;
void solve() {
    cin >> a >> b;
    row[a] = 1;
    col[b] = 1;
    diag_r[a + b] = 1;
    diag_l[a - b + 8] = 1;
    back(1, vector<int>(9, 0));
    sortv(out);
    cout<<"SOLN       COLUMN\n";
    cout<<" #      1 2 3 4 5 6 7 8\n\n";
    for (int i = 0; i < out.size(); ++i) {
        cout<<right<<setw(2)<<i+1<<"      ";
        for (int j = 1; j < 9; ++j) {
            cout<<out[i][j];
            if(j!=8)cout<<" ";
        }
        cout<<'\n';
    }
    if(t)
    cout<<'\n';
    row[a] = 0;
    col[b] = 0;
    diag_r[a + b ] = 0;
    diag_l[a - b + 8] = 0;
    out.clear();
}


int main() {

//    freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
    allam

    cin >> t;
    while (t--) {
        solve();
    }

}
