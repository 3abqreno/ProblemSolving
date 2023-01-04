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
bool prime[1005]={};
//vector<int>p;
void sieve(int n){
    for (int i = 2; i <= n/2; ++i) {
        if(!prime[i]) {
//            p.push_back(i);
            for (int j = i + i; j <= n; j += i) {
                prime[j] = 1;
            }
            prime[i]=1;
        }
    }
}
void solve() {
    string s;
    cin >> s;
    sieve(s.size());
    int sz=s.size();
    int cnt=0;
    for(auto i:prime)cnt+=i;
    int c[26]={};
    for(auto i:s)c[i-'a']++;
    int idx=-1;
    for (int i = 0; i < 26; ++i) {
        if(c[i]>=cnt){
            idx=i;
            break;
        }
    }
    if(idx==-1)return void(cout<<"NO");
    cout<<"YES\n";
    vector<char>ans(s.size(),0);
    for (int i = 0; i <s.size() ; ++i) {
        if(prime[i+1]){
            ans[i]=idx+'a';
            c[idx]--;
        }
    }
    int cur=0;
    for (int i = 0; i < s.size(); ++i) {
        while(!c[cur])cur++;
        if(!ans[i])ans[i]=cur+'a',c[cur]--;
    }
    for(auto i:ans)cout<<i;

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
