#include <bits/stdc++.h>
#include<cmath>
#include<string>
using namespace std;
typedef long long ll;
const double pi = 3.14159265358979323846;
#define MOD 1000000007
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
 
long long fast_power(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
 
        if (power % 2 == 1) { // Can also use (power & 1) to make code even faster
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        power = power / 2; // Can also use power >>= 1; to make code even faster
    }
    return result;
}
ll factorial(ll n) {
    if (n == 0)
        return 1;
    ll factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}
float nCr(float n, float r)
{
    int i, res;
    if (r > 0)
        return (n / r) * nCr(n - 1, r - 1);
    else
        return 1;
}
 
int main() {
    int n,x;
    cin >> n;
    bool good = 1;
    vector<int>numbers(n);
    int l=-1, r=-1;
    cin >> numbers[0];
    for (int i = 1; i < n; i++)
    {
        
        cin >> numbers[i];
        if (numbers[i] < numbers[i - 1])
        {
            if (l ==-1) {
                l = i;
            }
            else if(r!=-1)
            {
                good = 0;
                break;
            }
        }
        else if (numbers[i] > numbers[i - 1] && l != -1) {
            if(r==-1)
            r = i;
           
        }
        
    }
    if (l == -1) {
        l = 1;
        r = 1;
    }
    if (l != -1 && r == -1)r = n;
    if (r!=n&&numbers[l - 1] > numbers[r])good = 0;
    if (l > 1 && numbers[r-1] < numbers[l - 2])good = 0;
    
    if (good) {
        cout << "yes"<<endl;
        
        cout << l  << ' ' << r ;
    }
    else
        cout << "no";
}
