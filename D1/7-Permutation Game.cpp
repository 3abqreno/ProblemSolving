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
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))

int index[int(1e5+1)];
int win[int(1e5+1)]={};
int a[int(1e5+1)];
vector<int>adj[int(1e5+1)];
void solve() {
    int n;cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        index[a[i]]=i;
    }
    for (int i =1; i <= n; ++i) {
        int x=index[i]+i;
        while(x<n){
            if(a[x]>i)adj[i].push_back(a[x]);
            x+=i;
        }
        x=index[i]-i;
        while(x>=0){
            if(a[x]>i)adj[i].push_back(a[x]);
            x-=i;
        }
    }
    for (int i = n-1 ; i ; --i) {
        for(auto v:adj[i]){
            win[i]|=(!win[v]);
        }
    }
    for (int i = 0; i < n; ++i) {
    cout<<(win[a[i]]?"A":"B");
    }


}

int main() {
    int t = 1;
//       freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);

    allam
//    cin >> t;
    while (t--) {
        solve();
//        cout << '\n';
    }

}
