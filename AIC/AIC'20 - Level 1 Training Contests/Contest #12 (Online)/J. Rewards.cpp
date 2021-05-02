//https://codeforces.com/group/aDFQm4ed6d/contest/279956/problem/J
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
    int x, c = 0, m = 0, n;
    for (int i = 0; i < 3; ++i)
    {
        cin >> x;
        c += x;
    }
    for (int i = 0; i < 3; ++i)
    {
        cin >> x;
        m += x;
    }
    cin >> n;
    while (n--)
    {
        if (c) c = max (c - 5, 0);
        else m = max (m - 10, 0);
    }
    cout << (c || m ? "NO" : "YES");
}

