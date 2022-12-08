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
  ll n,m,k,x,y,div;
  cin>>n>>m>>k>>x>>y;
  if(n==1){
      cout<<(k+m-1)/m<<" "<<k/m<<" "<<k/m+(k%m>=y);
      return;
  }
  if(k<n*m)return void(cout<<1<<" "<<0<<" "<<(k>=((x-1)*m+y)));
    k-=n*m;
  if(n==2){
        cout<<1+(k+n*m-1)/(n*m)<<" "<<1+(k)/(n*m*2-2*m)<<" ";
  }else
    cout<<1+(k+(n-1)*(m)-1)/((n-1)*(m))<<" "<<1+(k)/(n*m*2-2*m)<<" ";
  ll rot=1+(k)/((n-1)*(m)),mod=k%((n-1)*(m));

  if(x!=1&&x!=n){
      if((rot-1)&1)
          cout<<rot+(mod>=((x-2)*m+y));//up
      else //down
      cout<<rot+(mod>=((n-x-1)*m+y));

  }else if(x==n){
        ll serg=1+(k)/(n*m*2-2*m);
        if((rot-1)&1)serg+=(mod>=((n-2)*m+y));
        cout<<serg;
  }else{
      ll serg=1+(k)/(n*m*2-2*m);
      if((rot-1)&1)serg++;
      else serg+=((mod>=((n-2)*m+y)));
      cout<<serg;
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
