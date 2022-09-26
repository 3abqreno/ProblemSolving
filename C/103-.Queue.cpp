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
    #include <ext/pb_ds/assoc_container.hpp>

    using namespace __gnu_pbds;
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


    long long fast_power(long long base, long long power) {
        long long result = 1;
        while (power > 0) {

            if (power % 2 == 1) {
                result = (result * base);
            }
            base = (base * base);
            power >>= 1;
        }
        return result;
    }

    int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
    int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

    vector<int> v(1e6+1, 0);
    void solve() {
        int n, x, y, start, end, a, b;
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            v[x]++;
            v[y]--;
            mp[x] = y;
        }
        for (int i = 1; i < 1e6+1; ++i) {
            if (v[i] == 1) {
                start =i;
                break;
            }
        }
        a = 0, b = start;
        cout << start<<" ";
        for (int i = 0; i < n / 2; ++i) {
            x = mp[a];
            cout << x << " ";
            y = mp[b];
            a = x;
            b = y;
            if(i!=(n/2-1)||n&1)
            cout << y << " ";
        }
    }

    int main() {
        //freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
        allam
        int t = 1;
    //    cin >> t;
        while (t--) {
            solve();
        }

    }