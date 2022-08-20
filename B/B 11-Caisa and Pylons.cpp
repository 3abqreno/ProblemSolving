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
    int n;
    cin >> n;
    vector<int>numbers(n);
    for (auto &i : numbers) {
        cin >> i;
    }
    sort(numbers.begin(), numbers.end());
    cout << numbers[numbers.size() - 1];
}
