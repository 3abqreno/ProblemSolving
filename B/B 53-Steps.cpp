
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

int M[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
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

ll factorial(ll n) {
    if (n == 0)
        return 1;
    ll factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial = factorial * i % MOD;
    return factorial;
}

double nCr(double n, double r) {
    int i, res;
    if (r > 0)
        return (n / r) * nCr(n - 1, r - 1);
    else
        return 1;
}
ll cx,cy,n, m;
ll high;
int binarySearch(ll dx,ll dy){
    ll start,end,mid,index=0,tx=cx,ty=cy;
    start=1;
    end=high;

    while(true){
        if(start>=end)break;
        mid=start+(end-start)/2;
        if(tx+dx*mid>n||tx+dx*mid<1||ty+dy*mid>m||ty+dy*mid<1){
            end=mid;
        }
        else {
            start=mid+1;
            index=mid;
        }
    }
    if(start==end&&start>index)if(tx+dx*start<=n&&tx+dx*start>=1&&ty+dy*start<=m&&ty+dy*start>=1){
            index=start;
        }
    cx+=dx*index;
    cy+=dy*index;
    return index;
}
void solve() {
    ll k,dx,dy,count=0;
    cin >> n>>m>>cx>>cy>>k;
    high=max(n,m);
    for (int i = 0; i < k; ++i) {
        cin>>dx>>dy;
        count+=binarySearch(dx,dy);
    }
    cout<<count;
}


int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}