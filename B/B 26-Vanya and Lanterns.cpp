#include <bits/stdc++.h>
#include<cmath>
#include<string>
using namespace std;
typedef long long ll;
const double pi = 3.14159265358979323846;
#define MOD 1000000007
int dx[8] = { 0,0,1,-1,1,-1,1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,-1,1 };
int M[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int Primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229 };//50 primes
bool isPrime(int n)
{
	if (n == 2) return true;
	if (n < 2 || n % 2 == 0) return false;

	for (int i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
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
	ll  n, l;
	cin >> n >> l;
	vector<int>light(n);
	for (int i = 0; i < n; i++)
	{
		cin >> light[i];
	}
	sort(light.begin(), light.end());
	if (n == 1) {
		if ((light[0] - 0) > (l - light[0]))
		{
			cout << light[0] - 0;

		}
		else cout << l - light[0];
		return 0;
	}
	int Zeromax = light[0] - 0, max = light[1] - light[0], endmax = l- light[light.size() - 1];
	for (int i = 1; i < n; i++)
	{
		if (light[i] - light[i - 1] > max)
		{
			max = light[i] - light[i - 1];
		}
	}
	
	if (light[0] != 0) {
		if (light[light.size()-1]!=l&&endmax > Zeromax)
			Zeromax = endmax;
		if (Zeromax > float(max) / 2.0)
			cout << float(Zeromax);
		else
			cout << setprecision(12) << (max) / (2.0);
	}
	else
	{
		cout <<setprecision(12) << max / 2.0;
	}


}
