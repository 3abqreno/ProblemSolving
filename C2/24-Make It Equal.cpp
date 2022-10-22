//   _____       _
//  |____ |     | |
//     / / __ _| |__   __ _ _ __ ___ _ __   ___
//      \ \/ _` | '_ \ / _` | '__/ _ \ '_ \ / _ \
//  .___/ / (_| | |_) | (_| | | |  __/ | | | (_) |
//  \____/ \__,_|_.__/ \__, |_|  \___|_| |_|\___/
//                       | |
//                       |_|
#include<iostream>
#include <bits/stdc++.h>

#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

int a[200005]={};
void solve() {
  int n,k;
  cin>>n>>k;
    for (int i = 0; i < n; ++i) {
        int x;cin>>x;
        a[x]++;
    }
    int cnt=0,slice=0,ans=0;bool ok=0;
    for (int i = 200001; i >0 ; i--) {
        cnt+=a[i];
        if(cnt==n){
            if(a[i]==n)cout<<0;else
            cout<<(ans+ok);
            break;
        }
        if(slice+cnt<=k)slice+=cnt;
        else{
            slice =cnt,ans++,ok=0;
        }
       ok=1;
    }
}


int main() {
    int t = 1;
    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
    }

}
