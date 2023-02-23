#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
typedef long long ll;
int a[int(1e5+1)];

void solve() {
int n;cin>>n;
set<ll>s;
ll sum=0,sum2=0;
    for (int i = 0; i < n; ++i) {
    cin>>a[i];sum+=a[i];
    }
    for (int i = 0; i < n; ++i) {
        sum2+=a[i];
        if((!((2*sum2-sum)&1)&&s.contains((2*sum2-sum)>>1))||(2*sum2==sum))return void(cout<<"YES");
        s.insert(a[i]);
    }
    sum2=0;s.clear();
    for (int i = n-1; ~i ; --i) {
        sum2+=a[i];
        if((!((2*sum2-sum)&1)&&s.contains((2*sum2-sum)>>1))||(2*sum2==sum))return void(cout<<"YES");
        s.insert(a[i]);
    }
    cout<<"NO";
}


int main() {
    int t = 1;
//       freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);
     ios_base::sync_with_stdio(false);cin.tie(nullptr);
//    cin >> t;
    while (t--) {
        solve();
//        if (t)cout << '\n';
    }

}
