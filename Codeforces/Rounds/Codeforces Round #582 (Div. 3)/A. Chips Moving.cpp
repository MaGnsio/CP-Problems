//https://codeforces.com/problemset/problem/1213/A
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

int main ()
{
	ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
	int n;
	cin >> n;
	int cnto = 0;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		//number of chips with odd coordinate
		cnto += x & 1;
	}
	cout << min (cnto, n - cnto);
}
