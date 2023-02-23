#include <bits/stdc++.h>

using namespace std;
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
typedef long long ll;
struct segTree{
    vector<int>v;
    vector<int>lazy;
    int size=1;
    void init(int n){while(size<n)size<<=1;v.assign(2*size,0),lazy.assign(2*size,-1);}
    void build(string &s,int u,int l,int r){
        if(r-l==1){
            if(l<s.size())v[u]=s[l]-'0';return;
        }
        int  md=(l+r)>>1;
        build(s,2*u+1,l,md),build(s,2*u+2,md,r);
        v[u]=v[2*u+1]+v[2*u+2];
    }
    void update(int u,int x){
        if(x<2)lazy[u]=x;
        else if(lazy[u]==-1)lazy[u]=2;
        else if(lazy[u]<2)lazy[u]=!lazy[u];
        else lazy[u]=-1;
    }
    void propagate(int u,int lx,int rx){
        if(!(~lazy[u])||rx-lx==1)return;
        if(lazy[u]<2) v[2*u+1]=v[2*u+2]=lazy[u]*((rx-lx)>>1);
        else v[2*u+1]=((rx-lx)>>1)-v[2*u+1],v[2*u+2]=((rx-lx)>>1)-v[2*u+2];
        update(2*u+1,lazy[u]);
        update(2*u+2,lazy[u]);
        lazy[u]=-1;
    }
    void set(int l,int r,int u,int lx,int rx,int x){
        propagate(u,lx,rx);
        if(lx>=r||l>=rx)return;
        if(lx>=l&&rx<=r){
        if(x<2)v[u]=(rx-lx)*x;
        else v[u]=(rx-lx)-v[u];
        lazy[u]=x;
        return;
        }
        int md=(lx+rx)>>1;
        set(l,r,2*u+1,lx,md,x),set(l,r,2*u+2,md,rx,x);
        v[u]=v[2*u+1]+v[2*u+2];
    }
    int query (int l,int r,int u,int lx,int rx){
        propagate(u,lx,rx);
        if(lx>=r||l>=rx)return 0;
        if(lx>=l&&rx<=r)return v[u];
        int md=(lx+rx)>>1;
        int a=query(l,r,2*u+1,lx,md)+query(l,r,2*u+2,md,rx);
        v[u]=v[2*u+1]+v[2*u+2];
        return a;
    }
};
void solve() {
    int m;cin>>m;
    string s,x;
    for (int i = 0; i < m; ++i) {
        int t;cin>>t>>x;
        for (int j = 0; j < t; ++j)s+=x;
    }
    segTree st;st.init(s.size());st.build(s,0,0,st.size);
    int q,c=1;cin>>q;
    for (int i = 0; i < q; ++i) {
    char a;int l,r;cin>>a>>l>>r;
    if(a=='F'){
    st.set(l,r+1,0,0,st.size,1);
    }else if(a=='E'){
    st.set(l,r+1,0,0,st.size,0);
    }else if(a=='I'){
    st.set(l,r+1,0,0,st.size,2);
    }else{
        cout<<"Q"<<c++<<": "<<st.query(l,r+1,0,0,st.size)<<'\n';
    }
    }
}

int main() {
    int t = 1;
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int c=1;
    cin >> t;
    while (t--) {
        cout<<"Case "<<c++<<":\n";
        solve();
//        if (t)cout << '\n';
    }

}
