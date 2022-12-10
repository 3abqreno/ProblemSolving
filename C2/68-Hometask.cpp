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
    string s;cin>>s;
    int n;cin>>n;
    vector<int> arr(26,-1);
    vector<pair<char,int>>v;
    for (int i = 0; i < n; ++i) {
        string p;cin>>p;
        arr[p[0]-'a']=p[1];
        arr[p[1]-'a']=p[0];
    }
    vector<int>cnt(26);
    int ans=0;
    for (int i = 0; i < s.size(); ++i) {
        int c1=1;
        while((i<s.size()-1)&&s[i+1]==s[i])c1++,i++;
        if((s[i+1])==arr[s[i]-'a']){
            char f=s[i+1],s2=s[i];i++;
            int c2=0;
            while(i<s.size()&&(s[i]==f||s[i]==s2)){
                c1+=(s[i]==s2);
                c2+=(s[i]==f);
                i++;
            }
//            cout<<char(f)<<" "<<char(s2)<<"\n";
            i--;
           ans+=min(c1,c2);
        }
    }
    cout<<ans;

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
