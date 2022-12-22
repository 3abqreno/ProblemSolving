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
int n,k;
cin>>n>>k;
map<ll,ll>mp;
for(int i=0;i<n;i++){
    int x;cin>>x;
    mp[x]++;
}
pair<ll,ll>ans={0,0};
deque<pair<ll,ll>>v;
ll total=0,cnt=0;
for(auto i:mp){
    if(!v.empty())
    total+=cnt*(i.first-v.back().first);
    cnt+=i.second;
    while(total>k){
        if(v.front().second*(i.first-v.front().first)<=(total-k)){
            total-=v.front().second*(i.first-v.front().first);
            cnt-=v.front().second;
            v.pop_front();
        }else{
            ll c=((total-k+(i.first-v.front().first)-1)/(i.first-v.front().first));
            v.front().second-=c;
            total-=(i.first-v.front().first)*c;
            cnt-=c;
        }
    }
    v.push_back({i.first,i.second});
    if(cnt>ans.first)ans={cnt,i.first};
}
cout<<ans.first<<" "<<ans.second;
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
