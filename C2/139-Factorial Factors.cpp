//   _____       _
//  |____ |     | |
//      / / __ _| |__   __ _ _ __ ___ _ __   ___
//      \ \/ _` | '_ \ / _` | '__/ _ \ '_ \ / _ \
//  .___/ / (_| | |_) | (_| | | |  __/ | | | (_) |
//  \____/ \__,_|_.__/ \__, |_|  \___|_| |_|\___/
//                       | |
//                       |_|
#include <bits/stdc++.h>
using namespace std;
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
typedef long long ll;
int a[int(1e6+5)]={};
void pre(){
    for (int i = 2; i <1e6+5; ++i) {
        if(a[i])continue;

        for (int j = i+i; j < 1e6+5; j+=i) {
        int temp=j;
        while(temp%i==0)a[j]++,temp/=i;
        }
        a[i]=1;
    }
    for (int i = 3; i < 1e6+5; ++i) {
        a[i]+=a[i-1];
    }
}
void solve() {
int n;
while(cin>>n){
    cout<<a[n]<<'\n';
}
}

int main() {
    int t = 1;
//       freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);
    allam
    pre();
//    cin >> t;
    while (t--) {
        solve();
//        cout << '\n';
    }

}
