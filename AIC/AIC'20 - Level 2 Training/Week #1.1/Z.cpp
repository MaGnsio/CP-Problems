//https://vjudge.net/contest/416230#problem/Z
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
    ld e, n;
    while (cin >> e >> n) cout << fixed << setprecision (0) << pow (n, 1.0 / e) << "\n";
}

