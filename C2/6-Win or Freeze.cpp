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

void solve() {
    ll q, f = 0;
    cin >> q;
    vector<int> factors;
    for (ll i = 2; i * i <= q; i++) {
        while (q % i == 0) {
            f++;
            factors.push_back(i);
            q /= i;
        }
    }
    if(q>1){
        f++;
        factors.push_back(q);
    }
    if(f==2){
        cout<<2;
    }
    else{
        cout<<1<<'\n';
        if(f==0)cout<<0;
        else cout<<factors[0]*factors[1];
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
