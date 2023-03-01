#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
typedef long long ll;
/*
 * 3 =>> 5
 * 2 + 3 +4
 * 1 2 3
 */
void solve(){
int a,b,n;cin>>a>>b>>n;
    for (int i = 0; i < n; ++i) {
        ll l,t,m;cin>>l>>t>>m;
        int lx=l,rx=1e7,r=-1;
        while(lx<=rx){
            int md=(lx+rx)>>1;
            ll sum=a*(md-l+1ll)+((md*(md-1ll))/2-((l-1ll)*(l-2ll))/2)*b;
            if(t*m>=sum&&t>=(a+(md-1ll)*b)){
                r=md;
                lx=md+1;
            }else rx=md-1;
        }
        cout<<r<<'\n';
    }
}

int main() {
    int t = 1;
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    cin >> t;
    while (t--) {
        solve();
        if (t)cout << '\n';
    }

}
