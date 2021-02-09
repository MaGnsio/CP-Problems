//https://vjudge.net/contest/416230#problem/R
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        if (((n & 1) && (k & 1) && (k * k <= n)) || (!(n & 1) && !(k & 1) && (k * k <= n))) cout << "YES\n";
        else cout << "NO\n";
    }
}

