
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
#include<cmath>
#include <unordered_map>

#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
#define F first
#define S second
using namespace std;
typedef long long ll;
const double pi = 3.14159265358979323846;
#define MOD 1000000007
#define fast  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1, -1};
int dy[8] = {1, -1, 0, 0};

long long gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll fastpow(ll b, ll e) {
    if (!e) {
        return 1;
    }
    if (e & 1) {
        return b * fastpow(b, e - 1);
    }
    ll x = fastpow(b, e / 2);
    return x * x;
}


void solve() {
    int n, m, x;
    cin >> n >> m;
    vector<vector<bool>> grid(101, vector<bool>(101, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> x;
            grid[i][j] = x;
        }
    }
    int one;
    bool ok;
    int cr=0,cc=0;
    vector<bool> r(101, 0), c(101, 0);
    for (int i = 0; i < n; ++i) {
        one = 0;
        ok=1;
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1) {
                if (one == -1) {
                    ok=0;
                    break;
                }
                one = 1;
            } else if (one == 1) {
                ok=0;
                break;
            } else one = -1;
        }
        if (one==1&&ok){
            r[i] = 1;
            cr++;
        }
    }
    for (int i = 0; i < m; ++i) {
        one = 0;
        ok=1;
        for (int j = 0; j < n; ++j) {
            if (grid[j][i] == 1) {
                if (one == -1) {
                    ok=0;
                    break;
                }
                one = 1;
            } else if (one == 1) {
                ok=0;
                break;
            } else one = -1;
        }
        if (one==1&&ok){
            cc++;
            c[i] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1 && (!r[i] && !c[j])) {
                cout<<"NO";
                return;
            }
        }
    }
    if((cr&&!cc)||(cc&&!cr)){
        cout<<"NO";
        return;
    }
    cout<<"YES"<<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (r[i]&& c[j])cout << 1;
            else cout << 0;
            cout << " ";
        }
        cout << endl;
    }


}

int main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt", "w", stdout);
    fast
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

}
