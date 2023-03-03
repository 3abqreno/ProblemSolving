#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
typedef long long ll;
vector<int>edges[1005];
vector<int>l[1005];
vector<int>r[1005];
void solve(){
int n;cin>>n;
    for (int i = 0; i < n; ++i) {
        int k;cin>>k;
        for (int j = 0; j < k; ++j) {
        int x;cin>>x;
        edges[i].push_back(x);
        l[(i+1)%n].push_back(x);
        r[(i-1+n)%n].push_back(x);
        }
        sortv(edges[i]);
    }
    for (int i = 0; i < n; ++i)sortv(r[i]),sortv(l[i]);
    int ans=0;
    for (int i = 0; i < n; ++i) {
        int x=0,y=0;
        if(edges[i].size()<2)continue;
        while(x<l[i].size()&&l[i][x]<edges[i][0])x++;
        while(y<r[i].size()&&r[i][y]<edges[i][0])y++;
        for (int j = 0; j < edges[i].size()-1; ++j) {
        int c1=0,c2=0;
            while(x<l[i].size()&&l[i][x]<edges[i][j+1])x++,c1++;
            while(y<r[i].size()&&r[i][y]<edges[i][j+1])y++,c2++;
        ans+=c1!=c2;
        }
    }
    cout<<ans;
}

int main() {
    int t = 1;
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    cin >> t;
    while (t--) {
        solve();
        if (t)cout << '\n';
    }

}
