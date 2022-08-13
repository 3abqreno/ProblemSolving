
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
bool seen[3][3];
string line[3];
bool bfs(int cx, int cy) {
	queue<pair<pair<int, int>, int>>q;
	q.push({ { cx, cy }, 0 });
	int	x = q.front().first.first;
	int y = q.front().first.second;
	q.pop();
	for (int i = 0; i < 8; i++)
	{
		x = cx + dx[i];
		y = cy + dy[i];
		if (x >= 0 && x < 3 && y < 3 && y >= 0) {
			if (line[x][y] == line[cx][cy])
			{
				q.push({ { x, y }, i });

			}

		}
	}
	int count = 0;
	int cx2, cy2;
	while (q.size()) {
		cx2 = q.front().first.first;
		cy2 = q.front().first.second;

		x = cx2 + dx[q.front().second];
		y = cy2 + dy[q.front().second];
		if (x >= 0 && x < 3 && y < 3 && y >= 0) {
			if (line[x][y] == line[cx][cy] && (!seen[x][y] || !seen[cx][cy] || !seen[cx2][cy2]))
			{
				seen[x][y] = 1;
				seen[cx2][cy2] = 1;
				count = 1;
			}
		}
		q.pop();
	}
	seen[cx][cy] = 1;
	return count;
}

void solve() {
	string word;
	while (cin >> word) {
		if (word == "end")return;

		for (int i = 0; i < 3; i++)
		{
			fill(seen[i], seen[i] + 3, 0);
		}
		for (int i = 0; i < 3; i++)
		{
			line[i] = word.substr(3 * i, 3);
		}
		map<char, int>freq;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				freq[line[i][j]]++;
			}
		}
		if (freq['O'] > freq['X'] || freq['O'] < (freq['X'] - 1)) {
			cout << "invalid" << endl;
			continue;
		}

		int count_x = 0, count_O = 0, temp;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (line[i][j] != '.')
					temp = bfs(i, j);
				else temp = 0;
				if (line[i][j] == 'O')count_O += temp;
				else count_x += temp;
			}
		}
		if ((freq['X'] + freq['O']) < 9 && !count_x && !count_O)cout << "invalid";
		else if (count_O && count_x)cout << "invalid";
		else if ((count_O && freq['O'] == freq['X']) || (count_x && freq['X'] == (freq['O'] + 1)) || (!count_x && !count_O))cout << "valid";
		else cout << "invalid";
		cout << endl;
	}
}
int main() {
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

}
