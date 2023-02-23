#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
typedef long long ll;
#define x first
#define y second
struct segTree{
    vector<pair<int,int>>v;
    int size=1;
    void init(int n){while(size<n)size<<=1;v.assign(2*size,{});}
    pair<int,int> op(pair<int,int >a,pair<int,int>b){
        pair<int,int>ret={b.x,a.y};
        if(a.x>b.y)ret.x+=a.x-b.y;
        else ret.y+=b.y-a.x;
        return ret;
    }
    void build(string s,int u,int l,int r){
        if(r-l==1){
            if(l<s.size())v[u]={s[l]=='(',s[l]==')'};
            return;
        }
        int md=(r+l)>>1;
        build(s,2*u+1,l,md),build(s,2*u+2,md,r);
        v[u]=op(v[2*u+1],v[2*u+2]);
    }
    void set(int i,int u,int l,int r){
        if(r-l==1){
            v[u]={!v[u].x,!v[u].y};
            return;
        }
        int md=(r+l)>>1;
        if(i<md)set(i,2*u+1,l,md);
        else set(i,2*u+2,md,r);
        v[u]=op(v[2*u+1],v[2*u+2]);
    }
};
void solve() {
    int n,q,k;
    string s;
    cin>>n>>s>>q;
    segTree st;st.init(n);st.build(s,0,0,st.size);
    for (int i = 0; i < q; ++i) {
        cin>>k;
        if(!k){
            if(st.v[0].x||st.v[0].y)cout<<"NO\n";
            else cout<<"YES\n";
        }
        else st.set(k-1,0,0,st.size);
    }
}

int main() {
    int t = 10;
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    cin >> t;
    int c=1;
    while (t--) {
        cout<<"Test "<<c++<<":\n";
        solve();
//        if (t)cout << '\n';
    }

}
