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

int  distance (int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
void solve() {
    int n,c=1;
    while(cin>>n&&n){
        if(c>1)cout<<'\n';
        vector<vector<int>>dp(n,vector<int>(n));
        vector<pair<int,int>>v(n);
        for (int i = 0; i < n; ++i) {
            cin>>v[i].first>>v[i].second;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                dp[i][j]=dp[j][i]= distance(v[i].first,v[i].second,v[j].first,v[j].second);
            }
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dp[i][j]=min(dp[i][j],max(dp[i][k],dp[k][j]));
                }
            }
        }
        cout<<"Scenario #"<<c<<"\nFrog Distance = "<<fixed<<setprecision(3)<<sqrt(dp[0][1])<<"\n";
        c++;
    }
    
}


int main() {
    int t = 1;
    //   freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }

}
