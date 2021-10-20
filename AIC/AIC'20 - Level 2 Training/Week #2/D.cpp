//https://vjudge.net/contest/417978#problem/D
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
    ll N, X;
    cin >> N;
    ll f[4] = {};
    while (N--)
    {
        cin >> X;
        f[X - 1]++;
    }
    f[0] = max (f[0] - f[2], 0ll);
	cout << f[2] + f[3] + (f[0] + f[1] * 2 + 3) / 4;
}

