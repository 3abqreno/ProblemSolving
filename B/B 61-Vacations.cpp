
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
        return b * fastpow(b, e - 1) % MOD;
    }
    ll x = fastpow(b, e / 2) % MOD;
    return x * x;
}

int binarySearch(vector<int> &numberrs, int value) {
    int start = 0, end = numberrs.size() - 1, mid, index = -1;
    while (start < end) {
        mid = start + (end - start) / 2;
        if (numberrs[mid] >= value) {
            end = mid;

        } else {
            start = mid + 1;
            index = mid;
        }
    }
    return index;

}
int n;
vector<int> days;
vector<vector<int>>minDays;
int findMin(int i,int parent,int ip) {
    if(i>=n)return 0;
    int mini=0;
    int index=days[i];
    if(minDays[i][parent]!=-1&&ip!=3)return minDays[i][parent];
    if(index==0)mini= findMin(i+1,0,0)+1;
    if(index==3){
        if(parent==1)mini= findMin(i+1,2,2);
        if(parent==2)mini= findMin(i+1,1,1);
        else if(parent==0){
            mini= min(findMin(i+1,1,3),findMin(i+1,2,3));
        }
    }

    if(index==1){
        if(parent==1)mini= findMin(i+1,0,1)+1;
        else mini= findMin(i+1,1,1);
    }
    if(index==2){
        if(parent==2)mini= findMin(i+1,0,2)+1;
        else mini= findMin(i+1,2,2);
    }
    minDays[i][parent]=mini;
    return mini;
}

void solve() {

    cin >> n;
    days.resize(n);
    minDays.resize(n,vector<int>(4,-1));
    for (int i = 0; i < n; ++i) {
        cin >> days[i];
    }
    cout<<findMin(0,0,0);

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

}
