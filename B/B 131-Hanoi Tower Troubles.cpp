
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
        return b * fastpow(b, e - 1);
    }
    ll x = fastpow(b, e / 2);
    return x * x;
}


int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

void solve() {
    int n;
    cin>>n;
    vector<ll>v(n,-1);
    ll i=1,temp;
    bool ok=1;
    while(ok){
        ok=0;
        for (int j = 0; j < n; ++j) {
            if(v[j]==-1){
                v[j]=i;
                ok=1;
                break;
            }
            else {
                temp=sqrt(v[j]+i);
                if(temp*temp==(v[j]+i))
                {
                    v[j]=i;
                    ok=1;
                    break;
                }
            }
        }
        i++;
    }
    cout<<*max_element(all(v))<<endl;
}


int main() {
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    // allam
    int t = 1;
    cin >> t;
    string c;
    getline(cin,c);
    while (t--) {
        solve();
    }

}
