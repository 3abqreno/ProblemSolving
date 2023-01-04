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
   int n,a,b;cin>>n>>a>>b;
   if(b==0&&a){
       if(a==n-1)return void(cout<<-1);
   }
  vector<int>v;
  int num=1,tot=0;
    for (int i = 0; i < b+1; ++i) {
        cout<<num<<" ";
        num<<=1;
    }
    if(b==0&&n>1)cout<<1<<" ",n--;
    num>>=1;
    for (int i = 0; i < a; ++i) {
        cout<<++num<<" ";
    }
    for (int i = 0; i < n-a-b-1; ++i) {
        cout<<1<<" ";
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
