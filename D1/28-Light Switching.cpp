//   _____       _
//  |____ |     | |
//      / / __ _| |__   __ _ _ __ ___ _ __   ___
//      \ \/ _` | '_ \ / _` | '__/ _ \ '_ \ / _ \
//  .___/ / (_| | |_) | (_| | | |  __/ | | | (_) |
//  \____/ \__,_|_.__/ \__, |_|  \___|_| |_|\___/
//                       | |
//                       |_|
#include <bits/stdc++.h>
using namespace std;
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
typedef long long ll;
struct segTree{
    vector<ll>v;
    vector<ll>lazy;
    int size;
    void init(int n){
        size=1;
        while(size<n)size<<=1;
        v.assign(2*size,0);
        lazy.assign(2*size,0);
    }
    void propagate(int u,int lx,int rx){
        if(rx-lx>1){
            if(lazy[u]&1){
            v[2*u+1]=((rx-lx)>>1)-v[2*u+1];
            v[2*u+2]=((rx-lx)>>1)-v[2*u+2];
            lazy[2*u+1]+=lazy[u];
            lazy[2*u+2]+=lazy[u];
            }
        }
        lazy[u]=0;
    }
    void set(int l,int r,int u,int lx,int rx){
        if(lx>=r||l>=rx)return;
        if(lazy[u])propagate(u,lx,rx);
        if(lx>=l&&rx<=r){
            v[u]=(rx-lx)-v[u];
            lazy[u]+=1;
            return;
        }
        int md=(lx+rx)>>1;
        set(l,r,2*u+1,lx,md),set(l,r,2*u+2,md,rx);
        v[u]=v[2*u+1]+v[2*u+2];
    }
    void set(int l,int r){
        set(l,r,0,0,size);
    }
    ll query(int l,int r,int u,int lx,int rx){
        if(lx>=r||l>=rx)return 0;
        if(lazy[u])propagate(u,lx,rx);
        if(lx>=l&&rx<=r)return v[u];
        int md=(lx+rx)/2;
        ll a= query(l,r,2*u+1,lx,md)+query(l,r,2*u+2,md,rx);
        v[u]=v[2*u+1]+v[2*u+2];
        return a;
    }
    ll query(int l,int r){
        return query(l,r,0,0,size);
    }
};

void solve() {
    int n,m;cin>>n>>m;
    segTree st;st.init(n);
    for (int i = 0; i < m; ++i) {
      int t,l,r;cin>>t>>l>>r;
      if(t){
         cout<<st.query(l-1,r)<<'\n';
      }else{
        st.set(l-1,r);
      }

    }
}


int main() {
    int t = 1;
//       freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);

    allam
//    cin >> t;
    while (t--) {
        solve();
//        if (t)cout << '\n';
    }

}
