//https://codeforces.com/group/aDFQm4ed6d/contest/279152/problem/F
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int a, b, c;
    cin >> a >> b >> c;
    cout << 4 * (sqrt (a * b / c) + sqrt (a * c / b) + sqrt (b * c / a));
}

