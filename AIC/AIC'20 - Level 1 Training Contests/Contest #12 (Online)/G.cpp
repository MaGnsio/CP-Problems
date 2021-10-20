//https://codeforces.com/group/aDFQm4ed6d/contest/279956/problem/G
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
    ll n;
    cin >> n;
    ll a[n];
    for (auto& x : a) cin >> x;
    ll x = 0, y = 0, z = 0;
    for (ll i = 0; i < n; ++i)
    {
        if (a[i] == 25) x++;
        else if (a[i] == 50)
        {
            if (x) x--, y++;
            else return cout << "NO", 0;
        }
        else
        {
            if (x && y) x--, y--, z++;
            else if (x >= 3) x -= 3, z++;
            else return cout << "NO", 0;
        }
    }
    cout << "YES";
}

