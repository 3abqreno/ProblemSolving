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

void solve() {
    int n,q;
    cin>>n>>q;
    vector<ll>s(n);
    cin>>s[0];
    ll total=s[0];
    for (int i = 1; i < n; ++i) {
        cin>>s[i];
        total+=s[i];
        s[i]+=s[i-1];
    }
    ll sum=0;
    for (int i = 0; i < q; ++i) {
        ll k;
        cin>>k;
        sum+=k;
        if(sum>=total){
            cout<<n<<'\n';
            sum=0;
            continue;
        }
        ll l=0,r=n-1,ans=0;
        while(l<=r){
            int md=(l+r)/2;
            if(s[md]>=sum){
                ans=md;
                r=md-1;
            }else l=md+1;
        }
        cout<<(n-ans-(sum==s[ans]))<<'\n';
    }


}


int main() {
    int t = 1;
    //   freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }

}
