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
    int n, r,t=1;
    while (cin >> n >> r) {
        if (!n && !r)return;
        vector<double> v(n);
        cout<<"Case "<<t<<":\n";
        t++;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        for (int i = 0; i < n; ++i) {
            double a = 0, b = 0;
            for (int j = 0; j <  (1 << n); ++j) {
                if (__builtin_popcount(j) == r) {
                    double p = 1;
                    for (int k = 0; k < n; ++k) {
                        if (j & (1 << k))p *= v[k];
                        else p *= 1 - v[k];
                    }
                    b += p;
                    if (j & (1 << i))a+=p;

                }
            }

            cout << fixed<<setprecision(6)<<a / b << '\n';
        }
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
