//https://codeforces.com/group/aDFQm4ed6d/contest/272103/problem/D
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
    ld ac, bc;
    cin >> ac >> bc;
    cout << fixed << setprecision (6) << 0.5 * 3.141592 * (((ac * ac) + (bc * bc)) / 4);
}

