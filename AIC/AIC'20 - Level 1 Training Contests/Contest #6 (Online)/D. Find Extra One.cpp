//https://codeforces.com/group/aDFQm4ed6d/contest/274872/problem/D
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
    ll N, p = 0, n = 0;
    cin >> N;
    while (N--)
    {
        ll x, y;
        cin >> x >> y;
        if (x < 0) p++;
        else n++;
    }
    if (p <= 1 || n <= 1) cout << "YES";
    else cout << "NO";
}

