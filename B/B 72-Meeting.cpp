
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
#include<string>

#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;
const double pi = 3.14159265358979323846;
#define MOD 1000000007
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int Primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
                101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
                211, 223, 227, 229};//50 primes
bool isPrime(int n) {
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

long long gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
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
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        power >>= 1;
    }
    return result;
}


double nCr(double n, double r) {
    int i, res;
    if (r > 0)
        return (n / r) * nCr(n - 1, r - 1);
    else
        return 1;
}

ll factorial(ll n) {
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
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


int countDivisors(int n) {
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                cnt++;

            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}

int binarySearch(vector<pair<int, int>> &ar, int value) {
    int start = 0, end = ar.size() - 1, mid, index = -1;
    while (start < end) {
        mid = start + (end - start) / 2;
        if (ar[mid].first >= value) {
            end = mid;

        } else {
            start = mid + 1;
            index = mid;
        }
    }
    return index;

}
vector<pair<pair<int, int>, int>> heat;
ll n;
bool isWarm(int x,int y){
    for (int i = 0; i < n; ++i) {
        if((fastpow((heat[i].first.first-x),2)+fastpow((heat[i].first.second-y),2))<=heat[i].second*heat[i].second)
        {
            return 1;
        }
    }
    return 0;
}

void solve() {
    ll a, b, c, d, x, y, r;
    cin >> a >> b >> c >> d;

    cin >> n;
   heat.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> r;
        heat[i] = {{x, y}, r};
    }
    bool up = 0;
    if (a > c) {
        swap(a, c);
    }
    if (b > d) {
        swap(b,d);
    }
    bool warm;
    ll count = 0;
    for (int i = a; i <=c ; ++i) {
        if(!isWarm(i,b))
            count++;
        if(!isWarm(i,d))
            count++;
    }
    for (int i = b+1; i <d ; ++i) {
        if(!isWarm(a,i))
            count++;
        if(!isWarm(c,i))
            count++;
    }

    cout<<count;
}

int main() {
//    freopen("input.txt","r",stdin);
//   freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }

}
