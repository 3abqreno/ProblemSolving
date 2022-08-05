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
bool isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
bool isDayNext(int x, int y, int z, int a, int b, int c) {
	if (c > z + 1)return 0;
	if (c == z+1) {
		if (a == 1 && b == 1 && y == 12 && x == 31)return 1;
		else return 0;
	}
	else {
		if (a == 1 && b == y + 1) {

			if ((y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10)) {
				if (x == 31)return 1;
				else return 0;
			}
			if ((y == 4 || y == 6 || y == 9 || y == 11)) {
				if (x == 30)return 1;
				else return 0;
			}
			if (isLeapYear(c)) {
				if (x == 29)return 1;
				else return 0;
			}
			else {
				if (x == 28)return 1;
				else return 0;
			}

		}
		else {
			if (b == y && a == x + 1)return 1;
			else return 0;
		}
	}
}
int main() {
	int n;
	while (cin >> n) {
		int  d, m, y, c, pd = -1, pm = -1, py = -1, pc = -1;
		int count = 0, sum = 0;
		
		if (n == 0)return 0;
		for (int i = 0; i < n; i++)
		{
			cin >> d >> m >> y >> c;
			if (isDayNext(pd, pm, py, d, m, y)) {
				count++;
				sum += (c - pc);

			}

			pd = d;
			pm = m;
			py = y;
			pc = c;
		}
		cout << count << " " << sum << endl;
	}
}
