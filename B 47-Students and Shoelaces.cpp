
//   _____       _                                
//  |____ |     | |                               
//     / / __ _| |__   __ _ _ __ ___ _ __   ___  
//      \ \/ _` | '_ \ / _` | '__/ _ \ '_ \ / _ \ 
//  .___/ / (_| | |_) | (_| | | |  __/ | | | (_) |
//  \____/ \__,_|_.__/ \__, |_|  \___|_| |_|\___/ 
//                       | |                     
//                       |_|                     
#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#include<string>
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
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

		if (power % 2 == 1) {
			result = (result * base) % MOD;
		}
		base = (base * base) % MOD;
		power >>= 1;
	}
	return result;
}
ll factorial(ll n) {
	if (n == 0)
		return 1;
	ll factorial = 1;
	for (int i = 2; i <= n; i++)
		factorial = factorial * i % MOD;
	return factorial;
}
double nCr(double n, double r)
{
	int i, res;
	if (r > 0)
		return (n / r) * nCr(n - 1, r - 1);
	else
		return 1;
}
vector<vector<int>>enemy(101);
bool seen[101];
bool done[101];
int n,m;
bool dfs(int i) {
	seen[i] = 1;
	int ok=0;
	int size = enemy[i].size();
	vector<int>temp = enemy[i];
	for (auto x : temp) {
		if (!seen[x]) {
			ok +=dfs(x);
		}
	}
	if (size == 1) {
		if (enemy[i].size() == 1) {
			int temp = enemy[i][0];
			enemy[temp].erase(find(enemy[temp].begin(), enemy[temp].end(), i));
		}
		done[i] = 1;
		return  1;
	}
	else if (size == 0) {
		done[i] = 1;
		return 0;
	}
	else return ok;
}
void solve() {
	int a, b;
	cin >> n>>m;
	for (int i = 0; i < m; i++)
	{
		cin >> a>> b;
		enemy[a].push_back(b);
		enemy[b].push_back(a);
	}
	int count=0;
	bool end = 1,group=0;
	while (true)
	{
		end = 1;
		group = 0;
		fill(seen, seen + 101, 0);
		for (int i = 1; i < n + 1; i++)
		{

			if (!done[i] && !seen[i]) {
				group += dfs(i);
				end = 0;
			}
		}
		if (end || !group)break;
		else count++;
	}
	cout << count;

}
int main() {
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

}
