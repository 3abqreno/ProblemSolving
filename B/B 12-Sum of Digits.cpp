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
    string number;
    cin >> number;
    int count = 0,sum;
    while (true)
    {
        
        if (number.length()<=1)
            break;
        sum = 0;
        for (int i = 0; i < number.length(); i++)
        {
            sum += number[i] - '0';
        }
        number = to_string(sum);
        count++;
    }
    cout << count;
}
