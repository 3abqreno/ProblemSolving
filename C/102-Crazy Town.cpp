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

ll a[301],b[301],c[301];
void solve() {
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a[i]>>b[i]>>c[i];
    }
    int ans=0;
    for (int i = 0; i < n; ++i) {
        if(b[i]==0){
           long double ax=a[i];
           bool a=(x1>(-c[i]/ax)),b=((x2>(-c[i]/ax)));
            if(a^b)ans++;

        }
        else if(a[i]==0){
            long double ay=b[i];
            bool a=(y1>(-c[i]/ay)),b=((y2>(-c[i]/ay)));
            if(a^b)ans++;

        }
        else{
            bool f=(y1*b[i]>(-c[i]-a[i]*x1)),s=((y2*b[i]>(-c[i]-a[i]*x2)));
            if(s^f)ans++;
        }
    }
    cout<<ans;
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
