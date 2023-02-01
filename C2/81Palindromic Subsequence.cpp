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
string s,temp;
pair<int,string> dp[1005][1005];
bool dp2[1005][1005];
pair<int,string>go(int i,int j){
pair <int,string> &ret=dp[i][j];
if(~ret.first)return ret;
if(i>j)return {0,""};
if(i==j)return {0,temp =s[i]};
if(s[i]==s[j]){
    ret=go(i+1,j-1);
    ret.second=s[i]+ret.second+s[j];
}else{
    pair <int,string>c=go(i+1,j),c2=go(i,j-1);
    c.first++;c2.first++;
    ret=min(c,c2);
}
return ret;
}

void solve() {
  while(cin>>s&&s!="0"){
    for(int i=0;i<s.size()+1;i++)for(int j=0;j<s.size()+1;j++)dp[i][j].first=-1;
    cout<<go(0,s.size()-1).second<<'\n';
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
        if (t)cout << '\n';
    }

}
