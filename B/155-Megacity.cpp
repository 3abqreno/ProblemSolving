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

#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

struct node {
    ll x, y, p;

    node() {}

    node(int a, int b, int po) {
        x = a;
        y = b;
        p = po;
    }
};
ll n, s,total;
vector<node>v;

bool isPossible(long double a){
    ll t=s;
    for (int i = 0; i < n; ++i) {
        if((v[i].x*v[i].x)+(v[i].y*v[i].y)<=a*a)t+=v[i].p;
    }
    return t>=1000000;
}

void solve() {
    cin >> n >> s;
    total=s;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i].x>>v[i].y>>v[i].p;
        total+=v[i].p;
    }
    if(total<(1000000)){
        cout<<-1;return;
    }
    long double l=0,r=1e10,md,ans;
    for (int i = 0; i < 60; ++i) {
        md = (l + r) / 2;
        if(isPossible(md)){
            ans=md;
            r=md;
        }
        else l=md;
    }
    cout<<setprecision(15)<<ans;
}

int main() {
    int t = 1;
    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
    }

}
