	#include <bits/stdc++.h>
	#include<cmath>
	#include<string>
	using namespace std;
	typedef long long ll;
	const double pi = 3.14159265358979323846;
	#define MOD 1000000007
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

	void check(int i, int k,int &count, vector<string>& pixels, vector<vector<bool>>& checked) {
		if (checked[i][k] == 0 && !(checked[i + 1][k] == 1 || checked[i + 1][k + 1] == 1 || checked[i - 1][k] == 1 || checked[i + 1][k - 1] == 1 || checked[i - 1][k - 1] == 1 || checked[i - 1][k + 1] == 1 || checked[i][k + 1] == 1 || checked[i][k - 1] == 1)) {
			count++;
		}
		checked[i][k] = 1;
		if (pixels[i + 1][k] == '1') {
	
			if (checked[i + 1][k] != 1) {
				checked[i + 1][k] = 1;
				check(i + 1, k, count, pixels, checked);
			}
		
		}
		if (pixels[i + 1][k + 1] == '1') {
	
			if (checked[i + 1][k + 1] != 1)
			{
				checked[i + 1][k + 1] = 1;
				check(i + 1, k + 1, count, pixels, checked);
			}
	
		}
		if (pixels[i - 1][k] == '1') {
	
			if (checked[i - 1][k] != 1) {
				checked[i - 1][k] = 1;
				check(i - 1, k, count, pixels, checked);
			}

		}
		if (pixels[i][k - 1] == '1') {
		
			if (checked[i][k - 1] != 1) {
				checked[i][k - 1] = 1;
				check(i, k - 1, count, pixels, checked);
			}
	
		}
		if (pixels[i][k + 1] == '1') {
		
			if (checked[i ][k + 1] != 1){
				checked[i][k + 1] = 1;
				check(i, k + 1, count, pixels, checked);
			}
	
		}
		if (pixels[i - 1][k + 1] == '1') {
		
			if (checked[i - 1][k + 1] != 1) {

				checked[i - 1][k + 1] = 1;
				check(i - 1, k + 1, count, pixels, checked);
			}
	
		}
		if (pixels[i - 1][k - 1] == '1') {
		
			if (checked[i - 1][k - 1] != 1) {
				checked[i - 1][k - 1] = 1;
				check(i - 1, k - 1, count, pixels, checked);
			}
		
		}
		if (pixels[i + 1][k - 1] == '1') {
		
			if (checked[i + 1][k - 1] != 1)
			{
				checked[i + 1][k - 1] = 1;
				check(i + 1, k - 1, count, pixels, checked);
		
			}
		}
	}

	int main() {
		int n,c=0;
		while (cin >> n) {
			c++;
			int count=0;
			vector<string>pixels(n+2);
			vector<vector<bool>>checked(n+2,vector<bool>(n+2,0));
			for (int i = 0; i < n+2; i++)
			{
				pixels[0] += '0';
				pixels[n + 1] += '0';
			}
			for (int i = 1; i <= n; i++)
			{
			
					cin >> pixels[i];
					pixels[i] = '0' + pixels[i] + '0';
			
			}
			for (int i = 1; i <= n; i++)
			{
				for (int k = 1; k <= n; k++)
				{
					if (pixels[i][k] == '1') {
						if(checked[i][k]!=1)
						check(i,k,count,pixels,checked);
					
					}
				}
			}
			cout << "Image number "<< c<<" contains "<< count<<" war eagles."<<endl;
		}
	}
