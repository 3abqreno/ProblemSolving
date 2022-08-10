
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
//int dx[8] = { 0,0,1,-1,1,-1,1,-1 };
//int dy[8] = { 1,-1,0,0,1,-1,-1,1 };
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
int n, m;
pair<int, int>start;
pair<int, int>finish;
int dx [] = {1,-1,0};
int dy [] = {0,0,-1};
map<char,bool>correct;
char way[9][9];
vector<int>dir;
vector<vector<bool>>seen(9,vector<bool>(9,0));
bool dfs(int i,int j) {
	
	int cx = i, cy = j,x,y;
	for (int f = 0; f < 3; f++)
	{
		x = cx + dx[f];
		y = cy + dy[f];
		if (x >= 0 && x < m && cy >= 0 && cy < n) {
			if (correct[char(way[y][x])]&&!seen[y][x]) {
				seen[y][x] = 1;
				if (dfs(x, y)) {
					dir.push_back(f);
					return true;
				}
				
			}
			if (way[y][x] == '#') { 
				dir.push_back(f);
				return true; }
			
		}
	}
	return false;
}

void solve() {
	seen.clear();
	seen.resize(9,vector<bool>(9,0));
	dir.clear();
	cin >> n >> m;
	correct['I'] = 1;
	correct['E'] = 1;
	correct['H'] = 1;
	correct['O'] = 1;
	correct['V'] = 1;
	correct['A'] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> way[i][j];
			if (way[i][j] == '@')
				start = { j,i };
			else if (way[i][j] == '#')
				finish = { j,i };
		}
	}
	dfs(start.first, start.second);
	reverse(all(dir));
	for (int i = 0; i < dir.size();i++) {
		if (dir[i] == 0)cout << "right";
		else if (dir[i] == 1)cout << "left";
		else cout << "forth";
		if (i != dir.size() - 1)
			cout << " ";
	}
	cout << endl;

	
}

int main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

}
