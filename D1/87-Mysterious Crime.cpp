#include <bits/stdc++.h>

#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(m, vector<int>(n));
    vector<vector<int>> index(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
            v[i][j]--;
            index[i][v[i][j]] = j;
        }
    }
    ll ans=n;
    for (int i = 0; i < n; ++i) {
        int num = v[0][i], take = 0;
        vector<int> ind(m);
        for (int j = 1; j < m; ++j) {
            ind[j] = index[j][num];
        }
        bool ok = 1;
        while (i < n - 1 ) {
            int next = v[0][++i];
            ok = 1;
            for (int j = 1; j < m; ++j) {
                if (ind[j] == n - 1 || (index[j][next] != ind[j] + 1)) {
                    ok = 0;
                    break;
                } else ind[j]++;
            }
            if(!ok){
                i--;
                break;
            }
            else take++;
        }
        ans+= (take*(take+1ll))/2;
    }
    cout<<ans;

}

int main() {
    //freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
    allam
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}
