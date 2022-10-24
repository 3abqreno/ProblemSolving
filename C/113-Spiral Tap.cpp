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

#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define allam  ios_base::sync_with_stdio(false);cin.tie(nullptr);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int n, cnt = 0;

void print(int x,int y){
    cout<<"Line = "<<y<<", column = "<<x<<".\n";
}
void solve() {
    int n, p;
    while (cin >> n >> p) {
        if (!n && !p)return;
        int x = n / 2 + 1, y = n / 2 + 1;
        if (p == 1) {
            print(x,y);
            continue;
        }
        y++;
        int power = 1;
        while ((power + 2) * (power + 2) < p) {
            power += 2;
            x++;
            y++;
        }
        p -= power * power;
        p--;
        power+=2;
        if(!p){
            print(x,y);

            continue;
        }
        for (int i = 0; i < power-2; ++i) {
            x--;
            p--;
            if(!p){
                print(x,y);

                break;
            }
        }if(!p)continue;
        for (int i = 0; i < power-1; ++i) {
            y--;
            p--;
            if(!p){
                print(x,y);

                break;
            }
        }
        if(!p)continue;
        for (int i = 0; i < power-1; ++i) {
            x++;
            p--;
            if(!p){
                print(x,y);

                break;
            }
        }if(!p)continue;
        for (int i = 0; i < power-1; ++i) {
            y++;
            p--;
            if(!p){
                print(x,y);

                break;
            }
        }
    }
}

int main() {
    int t = 1;
    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    allam
//    cin >> t;
    while (t--) {
        solve();
    }

}
