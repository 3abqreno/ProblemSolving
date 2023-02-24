#include <bits/stdc++.h>

using namespace std;
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
typedef long long ll;
string s;
struct trie {
    trie *child[10];
    bool isLeaf=0;
    trie(){memset(child,0,sizeof child);}

};
trie *temp;
bool insert() {
    for (int j = 0; j < s.size(); ++j) {
        if(temp->isLeaf){
            return 0;
        }
        if(!temp->child[s[j]-'0'])temp->child[s[j]-'0']=new trie();
        temp=temp->child[s[j]-'0'];
    }
    temp->isLeaf=1;
    return 1;
}

void solve() {
    int n;
    cin >> n;
    bool ans=1;
    trie *t=new trie;
    vector<string>v(n);
    for(auto &i:v)cin>>i;
    sort(all(v),[](string a,string b){return a.size()<b.size();});
    for (int i = 0; i < n; ++i) {
        temp=t;
        s=v[i];
        if(ans)ans&=insert();
    }
    cout<<(ans?"YES\n":"NO\n");

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
//        if (t)cout << '\n';
    }

}
