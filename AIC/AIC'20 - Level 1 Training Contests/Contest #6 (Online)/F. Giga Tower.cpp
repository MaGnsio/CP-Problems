//https://codeforces.com/group/aDFQm4ed6d/contest/274872/problem/F
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

bool chk8 (ll x)
{
    if (x < 0) x *= -1;
    while (x)
    {
        if(x % 10 == 8) return true;
        x /= 10;
    }
    return false;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll x, cnt = 1;
    cin >> x;
    x++;
    while (!chk8 (x)) x++, cnt++;
    cout << cnt;
}

