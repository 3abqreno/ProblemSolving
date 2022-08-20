#include <bits/stdc++.h>
 
#include<string>
using namespace std;
typedef long long ll;
const double pi = 3.14159265358979323846;
long long gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
long long lcm(int a, int b)
{
    if (a == 1 && b == 1)
    {
        return 1;
    }
    return (a / gcd(a, b)) * b;
}
 
 
int main() {
    int n, m;
    cin >> n >> m;
    map<int, int, greater<int>>matches;
    int x, y, sum = 0;
 
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        matches[y] += x;
    }
 
    for (auto i : matches) {
        if (n > i.second) {
            sum += i.first * i.second;
            n -= i.second;
        }
        else
        {
            sum += i.first * n;
            break;
        }
    }
    cout << sum;
}
