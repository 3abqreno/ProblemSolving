
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
   vector<pair<int,pair<int,int>>>v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i].second.first>>v[i].first;
        v[i].second.second=i+1;
    }
    sort(v.rbegin(),v.rend());
    int k;
    cin>>k;
    vector<pair<int,int>>s(k);
    for (int i = 0; i < k; ++i) {
        cin>>s[i].first;
        s[i].second=i+1;
    }
    sortv(s);
    int sum=0,cnt=0;
    vector<pair<int,int>>ans;
    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < s.size(); ++j) {
            if(s[j].first>=v[i].second.first){
                sum+=v[i].first;
                cnt++;
                ans.push_back({v[i].second.second,s[j].second});
                s.erase(s.begin()+j);
                break;
            }
        }
    }
    cout<<cnt<<" "<<sum<<endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }

}


int main() {
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    // allam
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}
