#include <bits/stdc++.h>

using namespace std;
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
typedef long long ll;
struct trie {
    trie * c[2];
    int freq;
    trie(){c[0]=c[1]=0,freq=0;}
};
int ans=0;
trie *temp;
void insert(int x,int add){
int c=__builtin_clz(x);
    for (int i = 0; i <= 31-c; ++i) {
    if(!temp->c[!!(x&(1<<(31-c-i)))])temp->c[!!(x&(1<<(31-c-i)))]=new trie;
    temp=temp->c[!!(x&(1<<(31-c-i)))];
    temp->freq+=add;
    }
}
void best(int x,int i){
    int c=__builtin_clz(x),best=0;
    for (int j = 31; j >i ; --j)best^=(x&(1<<j));
    for (int j = i; ~j ; --j) {
        if(x&(1<<j)){
          if(temp->c[0]&&temp->c[0]->freq){
              best^=(1<<j);
              temp=temp->c[0];
          }else if(temp->c[1]&&temp->c[1]->freq){
              temp=temp->c[1];
          }else return ;
        }else{
            if(temp->c[1]&&temp->c[1]->freq){
                best^=(1<<j);
                temp=temp->c[1];
            }else if(temp->c[0]&&temp->c[0]->freq){
                temp=temp->c[0];
            }else return ;
        }
    }
    ans=max(ans,best);
}
void solve() {
trie t[32];
int n=0,x,found=0;
cin>>n;
char c;
    for (int i = 0; i < n; ++i) {
       cin>>c>>x;
       int cnt=__builtin_clz(x);temp=&t[31-cnt];
       if(c=='+')
           insert(x,1);
       else if(c=='-')
           insert(x,-1);
       else{
           ans=x,found=0;
           for (int j = 0; j < 32; ++j) {
               if((t[j].c[0]&&t[j].c[0]->freq)||(t[j].c[1]&&t[j].c[1]->freq)){
                   temp=&t[j],found=1;
                   best(x,j);
               }
           }
           cout<<ans<<'\n';
       }
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
//        if (t)cout << '\n';
    }

}
