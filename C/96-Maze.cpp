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
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
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
char matrix[510][510];
bool vis[510][510];
int n, m, k,a=-1,b;
void dfs(int a,int b){
    int x,y;
    vis[a][b]=1;
    for (int i = 0; i < 4; ++i) {
        if(!k)return;
        x=a+dx[i];
        y=b+dy[i];
        if(x>=0&&x<n&&y>=0&&y<m&&matrix[x][y]=='.'&&!vis[x][y]){
            dfs(x,y);
        }
    }
    if(k){
        k--;
        matrix[a][b]='X';
    }

}

void solve() {
    for (int i = 0; i < 510; ++i) {
        memset(vis[i],0,510);
    }
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
            if(a==-1&&matrix[i][j]=='.')a=i,b=j;
        }
    }
    dfs(a,b);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout<<matrix[i][j];
        }
        cout<<'\n';
    }


}


int main() {
    //freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
    allam
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}
