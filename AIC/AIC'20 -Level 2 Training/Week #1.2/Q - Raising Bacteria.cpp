//https://vjudge.net/contest/416254#problem/Q
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
	ll n, ans = 0;
	cin >> n;
	while (n)
	{
		if (n & 1) ans++;
		n >>= 1;
	}
	cout << ans;
}

