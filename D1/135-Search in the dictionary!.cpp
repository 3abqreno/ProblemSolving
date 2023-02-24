#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
typedef long long ll;
vector<string>ans;
string s;
struct trie{
    trie * child[26];
    vector<string>v;
    trie(){
    memset(child,0,sizeof child);
    };
    void insert(int i){
        if(i==s.size())return void(v.push_back(s));
        if(!child[s[i]-'a'])child[s[i]-'a']=new trie();
        child[s[i]-'a']->insert(i+1);
    }
    void find(int i){
    if(i>=s.size()) {
        if(i>s.size())for(auto &j:v)ans.push_back(j);
        for (int j = 0; j < 26; ++j) {
            if(child[j])child[j]->find(i+1);
        }
    return;
    }
    if(!child[s[i]-'a'])return;
    child[s[i]-'a']->find(i+1);
    }
};

void solve() {
int n;cin>>n;
trie t;
set<string>ss;
    for (int i = 0; i < n; ++i) {
       cin>>s;
       if(ss.find(s)==ss.end())t.insert(0),ss.insert(s);
    }
    int q;cin>>q;
    for (int i = 1; i <=q; ++i) {
        cin>>s;
        ans.clear();
        t.find(0);
        cout<<"Case #"<<i<<":\n";
        sortv(ans);
        for(auto j:ans)cout<<j<<'\n';
        if(ans.empty())cout<<"No match.\n";
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
