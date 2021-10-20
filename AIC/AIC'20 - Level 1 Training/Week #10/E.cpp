//https://codeforces.com/group/Rv2Qzg0DgK/contest/290492/problem/E
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
    ll n, x;
    map<ll, ll> m;
    cin >> n;
    while (n--)
    {
        cin >> x;
        m[x]++;
    }
    for (auto& k : m)
    {
        if (k.S & 1)
        {
            cout << k.F;
            return 0;
        }
    }
}

