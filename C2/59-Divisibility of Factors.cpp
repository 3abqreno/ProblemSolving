//   _____       _
//  |____ |     | |
//      / / __ _| |__   __ _ _ __ ___ _ __   ___
//      \ \/ _` | '_ \ / _` | '__/ _ \ '_ \ / _ \
//  .___/ / (_| | |_) | (_| | | |  __/ | | | (_) |
//  \____/ \__,_|_.__/ \__, |_|  \___|_| |_|\___/
//                       | |
//                       |_|
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

bool prime[105]={};
int pCnt[105]={};
void sieve(int n){
    for (int i = 2; i <= n; ++i) {
        if(!prime[i]){
            pCnt[i]++;
            for (int j = i+i; j <=n ; j+=i) {
                int temp=j;
                while(temp%i==0)pCnt[i]++,temp/=i;
                prime[j]=1;
            }
        }
    }
}
void solve() {
    int a,b;
    while(cin>>a>>b) {
        memset(prime,0,sizeof prime);
        memset(pCnt,0,sizeof pCnt);
        if(!b)return;
        if((a==0||a==1)&&abs(b)!=1&&b){
            cout<<0<<'\n';
            continue;
        }
        sieve(a);
        bool flag=0;
        for (int i = 2; i <= a; ++i) {
            if (!prime[i]) {
                while (b % i == 0)b /= i, pCnt[i]--;
                if(pCnt[i]<0){
                    flag=1;
                    break;
                }
            }
        }
        if(flag||abs(b)!=1){
            cout<<0<<'\n';
            continue;
        }
        ll ans = 1;
        for (int i = 1; i <= a; ++i) {
            if (pCnt[i])ans *= (pCnt[i] + 1);
        }
        cout << ans << '\n';
    }
}


int main() {
    int t = 1;
    //   freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    allam
    //    cin >> t;
    while (t--) {
        solve();
//        cout << '\n';
    }

}
