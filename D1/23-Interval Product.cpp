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
    vector<int>v;
    int size=1;
    void init(int n){
        while(size<n)size<<=1;
        v.assign(2*size,1);
    }
    void build(vector<int>&a,int u,int lx,int rx){
        if(rx-lx==1){
            if(lx<a.size()) {
                if (!a[lx])v[u] = 0;
                else v[u] = (a[lx] > 0 ? 1 : -1);
            }
            return;
        }
        int md=(lx+rx)>>1;
        build(a,2*u+1,lx,md);
        build(a,2*u+2,md,rx);
        v[u]=v[2*u+1]*v[2*u+2];
    }
    void build(vector<int>&a){
        build(a,0,0,size);
    }
    void set(int i,int u,int lx,int rx,int x){
        if(rx-lx==1) {
         if(!x)v[u]=0;
         else v[u]=(x>0?1:-1);
         return;
        }
        int md=(lx+rx)>>1;
        if(i<md)set(i,2*u+1,lx,md,x);
        else set(i,2*u+2,md,rx,x);
        v[u]=v[2*u+1]*v[2*u+2];
    }
    void set(int i,int x){
        set(i,0,0,size,x);
    }
    int query(int l,int r,int u,int lx,int rx){
        if(lx>=r||l>=rx)return 1;
        if(lx>=l&&r>=rx)return v[u];
        int md=(lx+rx)>>1;
        return query(l,r,2*u+1,lx,md)*query(l,r,2*u+2,md,rx);
    }
    int query(int l,int r){
        return query(l,r,0,0,size);
    }

};

void solve() {
int n,q;
while(cin>>n>>q){
    vector<int>v(n);
    for(auto &i:v)cin>>i;
    segTree st;st.init(n);
    st.build(v);
    for (int i = 0; i < q; ++i) {
        char t;int a,b;cin>>t>>a>>b;
        if(t=='C'){
            st.set(a-1,b);
        }else{
            int ans=st.query(a-1,b);
            if(!ans) cout<<"0";
            else if(~ans)cout<<"+";
            else cout<<"-";
        }
    }
    cout<<'\n';
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
        if (t)cout << '\n';
    }

}
