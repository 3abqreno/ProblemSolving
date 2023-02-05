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
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;
vector<string> v1, v2;
int dp[1001][10001];
int go(int i,int j){
    if(i==v1.size()||j==v2.size())return 0;
    int &ret=dp[i][j];
    if(~ret)return ret;
    if(v1[i]==v2[j])ret=1+go(i+1,j+1);
    else  ret=max(go(i+1,j),go(i,j+1));
    return ret;
}
void solve() {
    int c=1;
    string s1, s2;
    while (getline(cin, s1)) {
        v1.clear(),v2.clear();
        getline(cin, s2);
        if(c<10)cout<<" ";
        cout<<c++<<". ";
        if(s1==""||s2==""){
            cout<<"Blank!\n";
            continue;
        }
        s1.push_back('-');
        s2.push_back('-');
        string temp;
        for (auto i: s1)
            if ((i <= 'z' && i >= 'a') || (i >= 'A' && i <= 'Z')||(i>='0'&&i<='9'))temp.push_back(i);
            else if (!temp.empty())v1.push_back(temp), temp.clear();
        for (auto i: s2) {
            if ((i <= 'z' && i >= 'a') || (i >= 'A' && i <= 'Z')||(i>='0'&&i<='9'))temp.push_back(i);
            else if (!temp.empty())v2.push_back(temp), temp.clear();
        }
        for (int i = 0; i < v1.size()+1; ++i) for (int j = 0; j < v2.size()+1; ++j)dp[i][j]=-1;
        int ans=go(0,0);
        cout<<"Length of longest match: "<<ans<<'\n';
    }
}

int main() {
    int t = 1;
//    freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);

    allam
//    cin >> t;
    while (t--) {
        solve();
        if (t)cout << '\n';
    }

}
