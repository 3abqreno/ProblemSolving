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

struct segTree {
    int size;
    vector<array<ll,4>> values;
    //0 pre
    //1 suf
    //2 seg
    //3 sum
    void init(int n) {
        size = 1;
        while(size<n)size<<=1;
        values.assign(size << 1, {0,0,0,0});
    }
    static array<ll,4> op(array<ll,4>a,array<ll,4>b){
        if(a[0]==-1e18)return b;
        if(b[0]==-1e18)return a;
        array<ll,4>out={0,0,0,0};
        out[0]=max(a[0],a[3]+b[0]);
        out[1]=max(b[1],b[3]+a[1]);
        out[2]=max({b[2],a[2],a[1]+b[0]});
        out[3]=a[3]+b[3];
        return out;
    }
    void build(vector<int>&a,int u,int lx,int rx){
        if(rx-lx==1){
            if(lx<a.size()){
                values[u]={a[lx],a[lx],a[lx],a[lx]};
            }
            return;
        }
        int m=(lx+rx)/2;
        build(a,2*u+1,lx,m);
        build(a,2*u+2,m,rx);
        values[u]=op(values[2*u+1],values[2*u+2]);
    }
    void build(vector<int>&a){
        build(a,0,0,size);
    }
    void set(int i, int v, int u, int lx, int rx) {
        if (rx - lx == 1) {
            int mx=max(v,0);
            return void(values[u]={mx,mx,mx,v});
        }
        int m = (lx + rx)>>1;
        if (i < m) set(i,v,2*u+1,lx,m);
        else set(i,v,2*u+2,m,rx);
        values[u]=op(values[2*u+1],values[2*u+2]);
    }
    void set(int i, int v) {
        set(i,v,0,0,size);
    }
    array<ll,4> query(int l,int r,int u,int lx,int rx){
        if(lx>=r||l>=rx)return {ll(-1e18),ll(-1e18),ll(-1e18),ll(-1e18)};
        if(lx>=l&&rx<=r)return values[u];
        int m=(lx+rx)>>1;
        array<ll,4> ql=query(l,r,u*2+1,lx,m),qr=query(l,r,u*2+2,m,rx);
        return op(ql,qr);
    }
    array<ll,4> query(int l,int r){
        return query(l,r,0,0,size);
    }


};

void solve() {
    int n, m;
    cin >> n;
    vector<int>v(n);
    segTree st;
    st.init(n);
    for(auto &i:v)cin>>i;
    st.build(v);
    cin>>m;
    for (int i = 0; i < m; ++i)  {
        int a,b;cin>>a>>b;
        cout<<st.query(a-1,b)[2]<<'\n';
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
