#include <bits/stdc++.h>

using namespace std;
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
typedef long long ll;

int n;

double get(double s1, double s2) {
    double s3;
    for (int j = 3; j <= n; ++j) {
        s3 = 2 * s2 + 2 - s1;
        if(s3 < 0)return -1;
        s1=s2,s2=s3;
    }
    return s3;
}

void solve() {
    double a, ans;
    while (cin >> n >> a) {
        ans = 1e15;
        double l = 0, r = a ;
        for (int j = 0; j < 50; ++j) {
            double md = (l + r) / 2, aa = get(a,md);
            if (aa >=0) r = md,ans=aa;
            else l = md;
        }
        assert(ans != 1e15);
        cout << fixed << setprecision(2) << ans << '\n';
    }


}


int main() {
    int t = 1;
//       freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    allam

//    cin >> t;
    while (t--) {
        solve();
        if (t)cout << '\n';
    }

}
