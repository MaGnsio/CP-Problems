//https://codeforces.com/group/aDFQm4ed6d/contest/277178/problem/I
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
    ld x, y, z;
    cin >> x >> y >> z;
    ld v = x * y * z;
    ld t = v / ((v / x) + (v / y) + (v / z));
    cout << fixed << setprecision (12) << t;
}

