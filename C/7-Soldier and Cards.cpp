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
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);


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
        return b * fastpow(b, e - 1) % MOD;
    }
    ll x = fastpow(b, e / 2) % MOD;
    return x * x % MOD;
}

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};


void solve() {
    int n,f,s, x;
    cin >> n>>f;
    deque<ll> a;
    deque<ll> b;
    deque<ll> a_2;
    deque<ll> b_2;
    for (int i = 0; i < f; ++i) {
        cin >> x;
        a.push_front(x);
    }
    cin>>s;
    for (int i = 0; i < s; ++i) {
        cin >> x;
        b.push_front(x);
    }
    a_2=a;
    b_2=b;
    int r=0;
    while(a.size()&&b.size()){
        if(*(a.end()-1)<*(b.end()-1)){
            b.push_front(*(a.end()-1));
            b.push_front(*(b.end()-1));
            b.pop_back();
            a.pop_back();
        }
        else{
            a.push_front(*(b.end()-1));
            a.push_front(*(a.end()-1));
            a.pop_back();
            b.pop_back();
        }
        if(a==a_2&&b==b_2||r>n*n*n){
            cout<<-1;
            return;
        }
        r++;
    }
    cout<<r<<" "<< (a.size()?1:2);

}


int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    allam
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

}
