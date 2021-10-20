//https://codeforces.com/group/aDFQm4ed6d/contest/279956/problem/D
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
    int a, b, c, i, chk = 0;
    cin >> a >> b >> c;
    for (i = 1; i < 1000; ++i)
    {
        ll x = a * 10 / b;
        if (x == c)
        {
            chk = 1;
            break;
        }
        a = a * 10 % b;
    }
    cout << (chk ? i : -1);
}

