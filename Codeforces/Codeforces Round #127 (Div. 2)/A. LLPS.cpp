//https://codeforces.com/problemset/problem/202/A
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
	string s;
	cin >> s;
	int i = s.size () - 1;
	sort (s.begin (), s.end ());
	do
	{
		cout << s[i];
		--i;
	} while (i >= 0 && s[i] == s[s.size () - 1]);
}
