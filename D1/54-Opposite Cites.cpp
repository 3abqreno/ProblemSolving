#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
typedef long long ll;
int a[int(1e5+5)];
void solve(){
int n;cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    if(n&1)return void(cout<<"NO");
    for (int i = 0; i < n/2; ++i) {
        if(~a[i+n/2]&&~a[i]&&a[i]!=a[i+n/2])return void(cout<<"NO");
    }
    cout<<"YES\n";
    for (int i = 0; i < n/2; ++i) {
        if(~a[i]){
            a[i+n/2]=a[i];
        }else {
            if(~a[i+n/2])a[i]=a[i+n/2];
            else a[i]=a[i+n/2]=1;
        }
        cout<<a[i]<<' ';
    }
    for (int i = n/2; i < n; ++i) {
        cout<<a[i]<<' ';
    }
}

int main() {
    int t = 1;
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
        if (t)cout << '\n';
    }

}
