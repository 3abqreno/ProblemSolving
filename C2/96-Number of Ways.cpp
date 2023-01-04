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
 int n;cin>>n;
 vector<ll>v(n);
 cin>>v[0];
    for (int i = 1; i < n; ++i) {
        cin>>v[i];
        v[i]+=v[i-1];
    }
    ll total=v.back();
    if(total%3)return void(cout<<0);
    vector<int>idx1;
    vector<int>idx2;
    for (int i = 0; i < n-2; ++i) {
        if(v[i]==total/3)idx1.push_back(i);
    }
    if(!idx1.empty())
    for (int i = idx1.front()+1; i <n-1 ; ++i) {
        if(v[i]-v[idx1.front()]==total/3)idx2.push_back(i);
    }
    ll ans=0;
    for (int i = 0,j=0; i < idx1.size(); ++i) {
        while(j<idx2.size()&&idx2[j]<=idx1[i])j++;
        ans+=idx2.size()-j;
    }
    cout<<ans;

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
