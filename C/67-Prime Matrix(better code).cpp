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
bool prime[100019];//the highest prime that i want to go to

void sieve(int n) {
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}



void solve() {
    memset(prime, 1, 100019);
    sieve(100019);
    prime[1] = 0;
    prime[0] = 0;
    int n, m;
    cin >> n >> m;
    int a;
   vector<int>rows(n,0),cols(m,0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>a;
             int x=a;
             while(!prime[x]){
                 x++;
             }

            rows[i] += x-a;
            cols[j] += x-a;
        }
    }

    int c = *min_element(all(rows)), b = *min_element(all(cols));
    cout << min(c, b);


}


int main() {
    //freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
    allam
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}
