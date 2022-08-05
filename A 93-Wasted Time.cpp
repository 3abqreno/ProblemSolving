#include <bits/stdc++.h>
#include<cmath>
#include<string>
using namespace std;
typedef long long ll;
const double pi = 3.14159265358979323846;
#define MOD 1000000007
int dx[8] = { 0,0,1,-1,1,-1,1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,-1,1 };
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

	int n, k;
	cin >> n >> k;
	int x, y, px = -30, py = -30;
	cin >> px >> py;
	double sum = 0;
	for (int i = 1; i < n; i++)
	{

		cin >> x >> y;
		sum += sqrt((x - px) * (x - px) + (y - py) * (y - py));
		px = x;
		py = y;
	}
	cout <<setprecision(10) << sum * k / 50;



}
