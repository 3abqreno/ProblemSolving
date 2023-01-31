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
int dp[205][35],d[205];
int n,m;
int go(int i,int j){
    int &ret=dp[i][j];if(~ret)return ret;
    ret=0;
    if(j==m)
        for (int k = i+1; k < n; ++k) {
            ret+=d[k]-d[i];
        }
    else{
        ret=1e9;
        for (int k = i+1; k < n-(m-j-1); ++k) {
            int temp=go(k,j+1);
            for (int l = i; l <k ; ++l) {
                temp+=min(d[l]-d[i],d[k]-d[l]);
            }
            ret=min(ret,temp);
        }
    }
    return ret;
}
vector<int>a;
void build(int i,int j){
    a.push_back(i);
    if(j==m)return;
    int ret=dp[i][j];
    int k=i+1;
    for (k = i+1; k < n-(m-j-1); ++k) {
        int temp=go(k,j+1);
        for (int l = i; l <k ; ++l) {
            temp+=min(d[l]-d[i],d[k]-d[l]);
        }
        if(ret==temp)break;
    }
    build(k,j+1);
}
void solve() {
    int c=1;
    while(cin>>n>>m&&n) {
        a.clear();
        for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)dp[i][j]=-1;
        for (int i = 0; i < n; ++i)cin >> d[i];
        sort(d,d+n);
        int ans=1e9,tot=0,index=0;
        for (int i = 0; i <(n-m+1); ++i) {
         int temp=go(i,1);
         if(i>0)tot+=(d[i]-d[i-1])*(i);
         temp+=tot;
         if(temp<ans)index=i,ans=temp;
        }
        build(index,1);
        a.push_back(a.back());
        int l=0,w=0;
        vector<pair<int,int>>anss;
        for (int i = a.front()+1; i < n; ++i) {
            if(abs(d[i]-d[a[w]])>abs(d[a[w+1]]-d[i]))anss.push_back({l+1,i}),w++,l=i;
        }
        anss.emplace_back(l+1,n);
        cout<<"Chain "<<c++<<'\n';
        for(int x=1;auto [i,j]:anss) {
            cout << "Depot " << x++ << " at restaurant " << a[x - 2] + 1 << " serves restaurant";
            if(i==j)cout<<" "<<i<<'\n';
            else cout<<"s " << i << " to " << j
                    << '\n';
        }
            cout<<"Total distance sum = "<<ans<<"\n\n";
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
