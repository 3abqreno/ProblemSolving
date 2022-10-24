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
ll a[2000005];
void solve() {
   int n;
   cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    if(n==1){
        cout<<a[0];
        return;
    }
    sort(a,a+n);
    reverse(a,a+n);
    ll ans=0;
    for (int i = 0; i <= __lg(n)/2; ++i) {
        for (int j = 0; j < 1<<(2*i); ++j) {
            ans+=a[j];
        }
    }
    cout<<ans;
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
