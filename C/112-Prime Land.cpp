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


void solve() {
 string s;
 while(true){
     getline(cin,s);
     if(s=="0")return;
     stringstream os;
     os<<s;
     int p,e,num=1;
     while(os>>p>>e){
         for (int i = 0; i < e; ++i) {
             num*=p;
         }
     }
     num--;
     map<int,int>mp;
     for (int i = 2; i*i<= num; ++i) {
         while(num%i==0){
             mp[i]++;
             num/=i;
         }
     }
     if(num>1)mp[num]++;
     for(auto it=mp.rbegin();it!=mp.rend();it++){
         cout<<it->first<<" "<<it->second<<" ";
     }
     cout<<'\n';
 }
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
