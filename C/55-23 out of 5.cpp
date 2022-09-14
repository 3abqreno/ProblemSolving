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
#include <unordered_map>

#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
#define F first
#define S second
using namespace std;
typedef long long ll;
const double pi = 3.14159265358979323846;
#define MOD 1000000007
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);


long long gcd(ll a, ll b) {
    if (b == 0)
        return a;
    if (a == 0)
        return b;
    return gcd(b, a % b) % MOD;
}

long long lcm(int a, int b) {
    if (a == 1 && b == 1) {
        return 1;
    }
    return (a / gcd(a, b)) * b;
}


long long fast_power(long long base, long long power) {
    long long result = 1;
    while (power > 0) {

        if (power % 2 == 1) {
            result = (result * base);
        }
        base = (base * base);
        power >>= 1;
    }
    return result;
}

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
vector<int> v(5);

bool dp(int num, vector<bool> vis, int c) {
    if (c == 5) {
        if(num==23){
            return 1;
        }
        else return 0;
    }
    for (int i = 0; i < 5; ++i) {
        if (!vis[i]) {
            vis[i] = 1;
            if (dp(num + v[i], vis, c + 1))return 1;
            if (dp(num * v[i], vis, c + 1))return 1;
            if (dp(num - v[i], vis, c + 1))return 1;
            vis[i]= 0;
        }
    }
    return 0;
}

void solve() {
    vector <bool>arr={0, 0, 0, 0, 0};
    while (cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4]) {
        if(v[0]==0&&v[1]==0&&v[2]==0&&v[3]==0&&v[4]==0){
            return;
        }
        bool ok=0;
        for (int i = 0; i < 5; ++i) {
            if(!ok)
            for (int j = i + 1; j < 5; ++j) {
                arr[i] = 1;
                arr[j] = 1;
                if (dp(v[i] + v[j], arr, 2)) {
                    ok=1;
                    cout << "Possible\n";
                    break;
                }
                if (dp(v[i] * v[j], arr, 2)) {
                    ok=1;
                    cout << "Possible\n";
                    break;
                }
                if (dp(v[j] - v[i], arr, 2) ){
                    ok=1;
                    cout << "Possible\n";
                    break;
                }
                if (dp(v[i] - v[j], arr, 2) ){
                    ok=1;
                    cout << "Possible\n";
                    break;
                }
                arr[j] = 0;
            }
            arr[i] = 0;
        }
        if(!ok)
        cout<<"Impossible\n";
        v.clear();
        v.resize(5);
    }

}


int main() {
    //freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
    //allam
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}
