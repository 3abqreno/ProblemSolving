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
bool checkdistane(pair<int, int>f, pair<int, int>s, int x) {
	if (((f.first - s.first) * (f.first - s.first) + (f.second - s.second) * (f.second - s.second)) <= x * x)return 1;
	else
		return 0;
}
int main() {
	int n, m, x;
	string in;
	cin >> n >> m >> x;
	
	vector<vector<pair<int, int>>>myMap(26);
	//map<char, vector<pair<int, int>>>myMap;
	vector<pair<int, int>>shift;
	for (int i = 0; i < n; i++)
	{
		cin >> in;
		for (int j = 0; j < m; j++)
		{
			if (in[j] == 'S')
				shift.push_back(pair<int,int>(i,j));
			else {
				myMap[in[j] - 'a'].push_back(pair<int,int>(i,j));
			}
		}
	}
	
	int q, count = 0;
	cin >> q;
	string word;
	cin >> word;
	bool otherHand;
	vector<int>dist(26,-1);
	for (int i = 0; i < q; i++)
	{
		otherHand = 1;
		if (myMap[tolower(word[i])-'a'].size() != 0) {
			if (word[i] != tolower(word[i])) {
				if (shift.size()!=0) {
					{
						if (dist[tolower(word[i]) - 'a'] == 1) {
							otherHand = 0;
							
						}
						else if (dist[tolower(word[i]) - 'a'] == 0) {
 
							
						}
						else
						for (int j = 0; j < shift.size(); j++)
						{
							for (int k = 0; k < myMap[char(tolower(word[i]))-'a'].size(); k++)
							{
 
 
								if (checkdistane(myMap[char(tolower(word[i]))-'a'][k], shift[j], x)) {
									dist[tolower(word[i]) - 'a'] = 1;
									otherHand = 0;
									break;
								}
							}
						}
 
					}
 
					if (otherHand) {
						dist[tolower(word[i]) - 'a'] = 0;
						count++;
					}
				}
				else {
					cout << "-1";
					return 0;
				}
			}
		}
		else {
			cout << "-1";
			return 0;
		}
	}
 
	cout << count;
}
