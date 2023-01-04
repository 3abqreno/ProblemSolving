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
    int n, temp;
    cin >> n;
    if (n < 6)cout << -1 << '\n';
    else {
        temp=n-3;
        for (int i = 2; i < temp+2; ++i) {
            cout<<1<<" "<<i<<'\n';
        }
        cout<<2<<" "<<n-1<<'\n';
        cout<<2<<" "<<n<<"\n";
    }
    for (int i = 0; i < n-1; ++i) {
        cout<<i+1<<" "<<i+2<<'\n';
    }

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
