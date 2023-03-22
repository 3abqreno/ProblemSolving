#include <bits/stdc++.h>

#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
#define Mask bitset<12>
using namespace std;
typedef long long ll;

int dp[1<<12];

int go(Mask mask){
    int &ret=dp[mask.to_ulong()];
    if(~ret)return ret;
    ret=mask.count();
    for (int i = 0; i < 11; ++i) {
        if(i<10&&mask[i]&&mask[i+1]&&!mask[i+2]) {
            Mask cpy=mask;
            cpy[i]=cpy[i+1]=0;
            cpy[i+2]=1;
            ret=min(ret,go(cpy));
        }
        if(!mask[i]&&mask[i+1]&&mask[i+2]){
            Mask cpy=mask;
            cpy[i]=1;
            cpy[i+1]=cpy[i+2]=0;
            ret=min(ret,go(cpy));
        }
    }
    return ret;

}

void solve() {
Mask mask;
    for (int i = 0; i < 12; ++i) {
        char c;cin>>c;
        if(c=='o')mask[i]=1;
    }
    cout<<go(mask);
}


int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    allam
    memset(dp,-1,sizeof dp);

    int _t = 1;
    cin >> _t;
    while (_t--) {
        solve();
       cout << '\n';
    }

}
