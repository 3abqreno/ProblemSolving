//   _____       _
//  |____ |     | |
//      / / __ _| |__   __ _ _ __ ___ _ __   ___
//      \ \/ _` | '_ \ / _` | '__/ _ \ '_ \ / _ \
//  .___/ / (_| | |_) | (_| | | |  __/ | | | (_) |
//  \____/ \__,_|_.__/ \__, |_|  \___|_| |_|\___/
//                       | |
//                       |_|
#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

void solve() {
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<pair<int,int>>v(26);
    for(auto i:s)v[i-'a'].first++;
    int all=26;
    for (int i = 0; i < 26; ++i) {
        v[i].second=i;
        if(!v[i].first)v[i].first=1e9,all--;
    }
    sortv(v);
    int cnt=0,mn=0;
    int a[26]={};
    for (int i = 0; i < 26; ++i) {
        if(v[i].first+cnt<=n)mn++,cnt+=v[i].first,a[v[i].second]=-1;
    }
    cout<<all-mn<<'\n';
    for(auto i:s)if(a[i-'a']!=-1)cout<<i;
}


int main() {
    int t = 1;
//    freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
    }

}
