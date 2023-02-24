#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
typedef long long ll;
string s,space;
struct trie{
    map<string,trie*>child;
    void insert(int i){
        string t;
        if(i>=s.size())return;
        int j=i;
        while(j<s.size()&&s[j]!='\\')t+=s[j],j++;
        if(!child[t])child[t]=new trie();
        child[t]->insert(j+1);
    }
    void print(){
        for(auto [i,j]:child){
            cout<<space<<i<<'\n';
            space+=' ';
            j->print();
            space.pop_back();
        }
    }

};

void solve() {
int n;
while(cin>>n) {
        trie t;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            t.insert(0);
        }
        t.print();
        cout<<'\n';
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
