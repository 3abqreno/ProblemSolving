//   _____       _
//  |____ |     | |
//     / / __ _| |__   __ _ _ __ ___ _ __   ___
//      \ \/ _` | '_ \ / _` | '__/ _ \ '_ \ / _ \
        //  .___/ / (_| | |_) | (_| | | |  __/ | | | (_) |
//  \____/ \__,_|_.__/ \__, |_|  \___|_| |_|\___/
//                       | |
//                       |_|
#include<iostream>
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//
//using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set_ll tree<ll, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<ll , null_type ,  less_equal<ll> , rb_tree_tag , tree_order_statistics_node_update>
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
#define F first
#define S second
using namespace std;
typedef long long ll;
const double pi = 3.14159265358979323846;
#define MOD 1000000007
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);


long long gcd(ll a, ll b) {
    if (b == 0)
        return a;
    if (a == 0)
        return b;
    return gcd(b, a % b) % MOD;
}

long long lcm(int a, int b) {
    if (a == 1 && b == 1) {
        return 1;
    }
    return (a / gcd(a, b)) * b;
}

int n, k, m;


long long fast_power(long long base, long long power) {
    long long result = 1;
    while (power > 0) {

        if (power % 2 == 1) {
            result = (result * base) % m;
        }
        base = (base * base) % m;
        power >>= 1;
    }
    return result % m;
}

int dx[8] = {0, 0, 1, -1};
int dy[8] = {1, -1, 0, 0};

void solve() {
    string s;
    cin >> s;
    vector<vector<int>> v(10);
    int sum = 0;
    vector<vector<int>> sol(2);
    for (int i = 0; i < s.size(); ++i) {
        v[s[i] - '0'].push_back(i);
        if ((s[i] - '0') % 3 == 2)sol[1].push_back(i);
        else if ((s[i] - '0') % 3 == 1)sol[0].push_back(i);
        sum += s[i] - '0';
    }
    sum %= 3;
    if (!sum) {
        cout << s;
        return;
    }
    if (s.size() == 1) {
        cout << -1;
        return;
    }
    if (sum == 1) {
        vector<int> a1;
        vector<int> a2;
        sortv(sol[0]);
        sortv(sol[1]);
        if (!sol[0].empty()) {
            a1.push_back(sol[0].back());
            if (a1[0] == 0)
                for (int i = 1; i < s.size(); ++i) {
                    if (s[i] != '0')break;
                    else a1.push_back(i);
                }
        }
        if (sol[1].size() > 1) {
            a2.push_back(sol[1].back());
            a2.push_back(sol[1][sol[1].size()-2]);
            if (a2[1] == 0) {
                int index=-1;
                for (int i = a2[1]+1; i < s.size(); ++i) {
                    if (s[i] != '0'){
                        index=i;
                        break;
                    }
                    else a2.push_back(i);
                }
                if(index==a2[0])
                for (int i = a2[0]+1; i < s.size(); ++i) {
                    if (s[i] != '0')break;
                    else a2.push_back(i);
                }
            }
        }
        if (!a1.empty() && !a2.empty()) {
            if (a1.size() < a2.size()) {
                for (int i = 0; i < a1.size(); ++i) {
                    s[a1[i]] = 'a';
                }
            } else
                for (int i = 0; i < a2.size(); ++i) {
                    s[a2[i]] = 'a';
                }
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != 'a')
                    cout << s[i];
            }
        } else if (!a1.empty()) {
            if (a1.size() == s.size()) {
                if (v[0].size())cout << 0;
                else cout << -1;
                return;
            }
            for (int i = 0; i < a1.size(); ++i) {
                s[a1[i]] = 'a';
            }
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != 'a')
                    cout << s[i];
            }
        } else {
            if (a2.size() == s.size()) {
                if (v[0].size())cout << 0;
                else cout << -1;
                return;
            }
            for (int i = 0; i < a2.size(); ++i) {
                s[a2[i]] = 'a';
            }
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != 'a')
                    cout << s[i];
            }
        }
    }
    else if (sum == 2) {
        vector<int> a1;
        vector<int> a2;
        sortv(sol[0]);
        sortv(sol[1]);
        if (!sol[1].empty()) {
            a1.push_back(sol[1].back());
            if (a1[0] == 0)
                for (int i = 1; i < s.size(); ++i) {
                    if (s[i] != '0')break;
                    else a1.push_back(i);
                }
        }
        if (sol[0].size() > 1) {
            a2.push_back(sol[0].back());
            a2.push_back(sol[0][sol[0].size()-2]);
            if (a2[1] == 0) {
                int index=-1;
                for (int i = a2[1]+1; i < s.size(); ++i) {
                    if (s[i] != '0'){
                        index=i;
                        break;
                    }
                    else a2.push_back(i);
                }
                if(index==a2[0])
                for (int i = a2[0]+1; i < s.size(); ++i) {
                    if (s[i] != '0')break;
                    else a2.push_back(i);
                }
            }
        }
        if (!a1.empty() && !a2.empty()) {
            if (a1.size() < a2.size()) {
                for (int i = 0; i < a1.size(); ++i) {
                    s[a1[i]] = 'a';
                }
            } else
                for (int i = 0; i < a2.size(); ++i) {
                    s[a2[i]] = 'a';
                }
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != 'a')
                    cout << s[i];
            }
        } else if (!a1.empty()) {
            if (a1.size() == s.size()) {
                if (v[0].size())cout << 0;
                else cout << -1;
                return;
            }
            for (int i = 0; i < a1.size(); ++i) {
                s[a1[i]] = 'a';
            }
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != 'a')
                    cout << s[i];
            }
        } else {
            if (a2.size() == s.size()) {
                if (v[0].size())cout << 0;
                else cout << -1;
                return;
            }
            for (int i = 0; i < a2.size(); ++i) {
                s[a2[i]] = 'a';
            }
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != 'a')
                    cout << s[i];
            }
        }
    }
}


int main() {

//    freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
    allam
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }

}
