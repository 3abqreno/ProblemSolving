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
	string first, second;
	int lastindex;
	
	while (cin >> first >> second) {
		reverse(first.begin(),first.end());
		reverse(second.begin(), second.end());
		if (first == "0" || second == "0") {
			cout << 0<<endl;
			continue;
		}
		vector<int>product(first.size() * second.size());
		for (int i = 0; i < first.size(); i++)
		{
			for (int j = 0; j < second.size(); j++)
			{
				product[(i) + (j )] += ((first[i] - '0') * (second[j] - '0'));
			}
		}
		for (int i = 0; i < product.size()-1; i++)
		{
			product[i + 1] += product[i] / 10;
			product[i] = product[i] % 10;
		}
		for (int i = 0; i < product.size(); i++)
		{
			if (product[i] != 0)lastindex = i;
		}
		for (int i = lastindex; i >=0; i--)
		{
			cout << product[i];
		}
		cout << endl;
	}
}
