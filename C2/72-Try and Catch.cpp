//   _____       _
//  |____ |     | |
//      / / __ _| |__   __ _ _ __ ___ _ __   ___
//      \ \/ _` | '_ \ / _` | '__/ _ \ '_ \ / _ \
//  .___/ / (_| | |_) | (_| | | |  __/ | | | (_) |
//  \____/ \__,_|_.__/ \__, |_|  \___|_| |_|\___/
//                       | |
//                       |_|
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1,0};
int dy[8] = {1, -1, 0,1};
const int MOD = 1000000007;
const int Pn=1e7+10;
int prime[Pn]={};
void sieve (int n){
    for (int i = 2; i < n; ++i) {
        if(!prime[i]){
            prime[i]=i;
            for (int j = i+i; j < n; j+=i) {
                prime[j]=i;
            }
        }
    }
}

void solve() {
    int n;cin>>n;
    stack<string>k;
    int cnt=0,c2=0;
    string th="";
    bool flag=0;
    for (int i = 0; i <= n; ++i) {
        string line,type,word;
        getline(cin,line);
        if(!line.size())continue;
        for (int j = 0; j < line.size(); ++j) {
            if(line[j]==' ')continue;
            else type.push_back(line[j]);
            if(type.size()==3&&type=="try"){
                flag?c2++:cnt++;break;
            }
            if(type.size()==5&&type=="throw") {
                for (int l = j+1; l < line.size(); ++l) {
                    if(line[l]=='('){
                        for (int m = l+1; m <line.size() ; ++m) {
                            if(line[m]!=')')th.push_back(line[m]);
                        }
                        int idx1=0,idx2=0;
                        for (int m = 0; m < th.size(); ++m) {
                            if(th[m]!=' '){
                                idx1=m;
                                break;
                            }
                        }
                        for (int m = th.size()-1; m >=0; m--) {
                            if(th[m]!=' '){
                                idx2=m;
                                break;
                            }
                        }
                        th=th.substr(idx1,idx2-idx1+1);
                    }
                }
                flag=1;
//                cout<<th<<'\n';
            }
            if(type.size()==5&&type=="catch") {
                if(c2){
                    c2--;
                    break;
                }
                for (int l = j+1; l < line.size(); ++l) {
                    if(line[l]=='('){
                        int m=l+1;
                        for (; m < line.size(); ++m) {
                            if(line[m]!=' '&&line[m]!=',')word.push_back(line[m]);
                            if(line[m]==',')break;
                        }
                        if(word!=th){
                            cnt--;
                            continue;
                        }
                        string out;
                        for (m=m+1; m <line.size() ; ++m) {
                            if(line[m]=='"') {
                                for (int i1 = m+1; i1 <line.size() ; ++i1) {
                                    if(line[i1]=='"')break;
                                    out.push_back(line[i1]);
                                }
                                break;
                            }
                        }
                        return void(cout<<out);
                    }
                }

            }
        }
    }
cout<<"Unhandled Exception";
}


int main() {
    int t = 1;
    //   freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
//        cout << '\n';
    }

}
