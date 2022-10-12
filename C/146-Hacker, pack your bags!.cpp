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

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

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


vector<pair<ll,ll>>l[int(2e5+2)];
vector<pair<ll,ll>>r[int(2e5+2)];
void solve() {
int n,x;
cin>>n>>x;
    for (int i = 0; i < n; ++i) {
        int L,R,C;
        cin>>L>>R>>C;
        r[R-L+1].push_back({R,C});
        l[R-L+1].push_back({L,C});
    }
    for (int i = 0; i < 2e5+2; ++i) {
        sortv(r[i]);
        sortv(l[i]);
    }
    ll ans=INT_MAX;
    for (int t = 1; t < x; ++t) {
        ll i=0,m=INT_MAX;
        for (int j = 0; j < l[x-t].size(); ++j) {
            while(i<r[t].size()&&r[t][i].first<l[x-t][j].first){
                m=min(m,r[t][i].second);
                i++;
            }
            ans=min(ans,m+l[x-t][j].second);
        }
    }
    if(ans==INT_MAX)cout<<-1;
    else cout<<ans;
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
