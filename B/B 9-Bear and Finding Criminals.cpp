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
    int n, start;
    cin >> n >> start;
    vector<int>criminals(n);
    for (int i=0; i<n ;i++)
    {
        cin >> criminals[i];
    }
    int distance = 0,counter=0;
    start--;
    while ((start - distance) >= 0 || (start + distance) <= n) {
        if ((start - distance) >= 0 && (start + distance) < n)
        {
            if ((criminals[start - distance] == 1) && (criminals[start + distance] == 1))
                if (distance == 0)
                    counter++;
                else
                    counter += 2;
        }
        else if ((start + distance < n)) {
            if (criminals[start + distance] == 1)
                counter++;
        }
        else if ((start - distance) >=0)
        {
            if (criminals[start - distance] == 1)
                counter++;
        }
        distance++;
    }
    cout << counter;
}
