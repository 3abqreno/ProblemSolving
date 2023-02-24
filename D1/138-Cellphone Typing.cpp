#include <bits/stdc++.h>

using namespace std;
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
typedef long long ll;
string s;
struct trie {
    trie *child[26];
    int freq=0;
    bool isLeaf=0;
    trie(){memset(child,0,sizeof child);}

};
trie *temp;
int cnt=0;
void insert() {
    for (int j = 0; j < s.size(); ++j) {
        if(!temp->child[s[j]-'a'])temp->child[s[j]-'a']=new trie();
        temp=temp->child[s[j]-'a'];
        temp->freq++;
    }
    temp->isLeaf=1;
}
void search(trie *node){
    int found=0,c=0;
    for (int i = 0; i < 26; ++i) {
      if(node->child[i])found++,search(node->child[i]),c+=node->child[i]->freq;
    }
    if(found>1||(found&&node->isLeaf))cnt+=c;
}

void solve() {
    int n;
    while(cin>>n){
        trie *node=new trie;cnt=0;
        for (int i = 0; i < n; ++i) {
            cin>>s;
            temp=node;
            insert();
        }
        for (int i = 0; i < 26; ++i){
            if(node->child[i])search(node->child[i]);
        }
        cout<<fixed<<setprecision(2)<<round((1+(cnt)/double(n))*100)/100<<"\n";
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
