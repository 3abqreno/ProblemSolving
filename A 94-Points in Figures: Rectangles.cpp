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

	char sign='0';
	double q, w, e, r,x=INT_MIN,y;
	vector<double>a;
	vector<double>b;
	vector<double>c;
	vector<double>d;
	int p=0;
	while (true) {
		
		if (sign != '*') {
			cin >> sign;
			if (sign == 'r') {
				cin >> q >> w >> e >> r;
				a.push_back(q);
				b.push_back(w);
				c.push_back(e);
				d.push_back(r);
			}
		}
		if (sign=='*') {

			p++;
			cin >> x;
			cin >> y;
			if (x == 9999.9)break;
			int count = 0;
			for (int i = 0; i < a.size(); i++)
			{

				double c1 = a[i] / 2+c[i]/2, cy1 = b[i] / 2+d[i]/2;
				double lengthx = fabs(a[i] - c[i]),lengthy=fabs(b[i]-d[i]);
				if (fabs(x-c1)<lengthx/2&&fabs(y-cy1)<lengthy/2 ) {
					count++;
					cout << "Point " << p << " is contained in figure " << i+1<<endl;
				}

			}
			if (count == 0) {
				cout << "Point " << p << " is not contained in any figure"<<endl;
			}
		}
		

	}


}
