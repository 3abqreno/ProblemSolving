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
int arr[200005];
void solve() {
   int n,curr=1;
   cin>>n;
   bool add=1;
   if(!(n&1)){
       cout<<"NO";return;
   }
    for (int i = 0; i < n; ++i) {
        arr[i]=curr;
        if(add){
            arr[i+n]=curr+1;
            curr+=3;
        }else{
        arr[i+n]=curr-1;
        curr++;
        }
        add=!add;
    }
    cout<<"YES\n";
    for (int i = 0; i < 2*n; ++i) {
        cout<<arr[i]<<" ";
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
