//   _____       _
//  |____ |     | |
//      / / __ _| |__   __ _ _ __ ___ _ __   ___
//      \ \/ _` | '_ \ / _` | '__/ _ \ '_ \ / _ \
    //  .___/ / (_| | |_) | (_| | | |  __/ | | | (_) |
//  \____/ \__,_|_.__/ \__, |_|  \___|_| |_|\___/
//                       | |
//                       |_|
#include <bits/stdc++.h>

#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

struct node {
    ll value;
    node *right = nullptr;
    node *left = nullptr;

    node() {}

    node(ll x) {
        value = x;
    }
};


struct myTree {
    node *root;

    myTree(int x) {
        root = new node(x);
    }
    void  insert(node *&root, int x) {
        if (!root) {
            root = new node(x);
            return;
        }
        if(root->value<x)insert(root->right,x);
        else insert(root->left,x);
    }

};

void solve() {
   ll n,x;
   cin>>n>>x;
   x--;
   vector<ll>v(n);
   int index=0;
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
        if(v[i]<v[index]){
            index=i;
        }
        if(v[i]==v[index]){
            int d1,d2;
            if(x>index)d1=x-index;
            else d1=(n-(index-x))%n;
            if(x>i)d2=x-i;
            else d2=(n-(i-x))%n;
            if(d2<d1)index=i;
        }
    }

    ll rem=v[index];
    if(x==index){
        v[index]*=n;
        for (int i = 0; i < n; ++i) {
            if(i==index)cout<<v[index]<<' ';
            else cout<<v[i]-rem<<" ";
        }
    }
    else{
        if(index<x){
            v[index]=v[index]*n+x-index;
            for (int i = 0; i < n; ++i) {
                if(i==index)cout<<v[index]<<" ";
                else if(i>index&&i<=x)cout<<v[i]-rem-1<<" ";
                else cout<<v[i]-rem<<" ";
            }
        }else{
        v[index]=v[index]*n+n-(index-x);
            for (int i = 0; i < n; ++i) {
                if(i==index)cout<<v[index]<<" ";
                else if(i<=x||i>index)cout<<v[i]-rem-1<<" ";
                else cout<<v[i]-rem<<" ";
            }

        }
    }


}

int main() {
    int t = 1;
    //    freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
    allam
    //    cin >> t;
    while (t--) {
        solve();
    }

}
