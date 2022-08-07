
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
int n, m;

vector<vector<int>>studens;
vector<int>vis(100);
int dfs(int parent, int count = 1) {
	vis[parent] = 1;
	for (auto& i : studens[parent]) {
		if (!vis[i] && i != parent && !studens[parent][i])
			count += dfs(i);
	}
	return count;
}
map<int, bool>taken;
bool valid(int a, int b) {
	if (b - a > 0 &&(b - a)<=9 && !taken[b - a])
		return 1;
	else
		return 0;
}
void solve() {
	ll d1, d2, c1, c2, r1, r2;
	cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
	int a1, a2, b1, b2;

	for (int i = 1; i <= 9; i++)
	{
		a1 = 0;
		b1 = 0;
		a2 = 0;
		taken.clear();
		b2 = i;
		taken[i]=1;
		if (valid(b2, c2)) {
			a2 = c2 - b2;
			taken[a2] = 1;
		}
		if (valid(b2, r2)) {
			b1 = r2 - b2;
			taken[b1]=1;
		}
		if (valid(b2, d1)) {
			a1 = d1 - b2;
		}
		if (a1 && b1 && c1)
		{
			if (d2 == (b1 + a2) && c1 == (a1 + b1) && r1 == (a1 + a2)) {
				cout << a1 << " " << a2 << endl;
				cout << b1 << " " << b2 << endl;
				return;
			}
		}


	}

	cout << -1;
}

int main() {
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

}
