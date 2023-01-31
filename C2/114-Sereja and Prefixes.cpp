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
int n;string s;
const int MOD=1e9+7;


void solve() {

    int n;cin>>n;
    vector<int>seq;
    vector<ll>where(n+1);
    vector<pair<int,int>>v;
    where[0]=0;
    for (int i = 1; i <= n; ++i) {
        int t;cin>>t;if(t==1){
            int a;cin>>a;seq.emplace_back(a);v.emplace_back(-1,a);where[i]=where[i-1]+1;
        }else {
            int a,b;cin>>a>>b;
            v.emplace_back(b,a);
            where[i]=where[i-1]+(a*ll(b));
            if(seq.size()<int(1e5+5))
                for (int j = 0; j < b; ++j) {
                    for (int k = 0; k < a; ++k) {
                        seq.emplace_back(seq[k]);
                        if(seq.size()>=int(1e5+5))break;
                    }
                    if(seq.size()>=int(1e5+5))break;
                }
        }
    }
    where.push_back(INTMAX_MAX);
    ll m,place=0,op=0;cin>>m;
    for (int i = 0; i < m; ++i) {
        ll x;cin>>x;
        while(where[op+1]<x)op++;
        if(v[op].first==-1)cout<<v[op].second<<" ";
        else{
            cout<<seq[(x-where[op]-1)%v[op].second]<<" ";
        }
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
        if(t)cout << '\n';
    }

}
