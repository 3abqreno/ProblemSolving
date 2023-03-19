#include <bits/stdc++.h>

#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;



void solve() {
    int n,length,v1,v2,k,c;
    cin>>n>>length>>v1>>v2>>k;
    c=((n+k-1)/k);
    long double div=1/(c+(c-1)*(1-double(v1)/v2)*(double(v2)/(v1+v2)));
    long double ans=length/((1-div)*v1+div*v2);
    cout<<fixed<<setprecision(12)<<ans;

}


int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    allam
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
        if (t)cout << '\n';
    }

}
