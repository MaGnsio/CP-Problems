//https://codeforces.com/group/aDFQm4ed6d/contest/275835/problem/H
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve ()
{
    ll n, o = 0, e = 0;
    cin >> n;
    ll a[n];
    for (auto& X : a)
    {
        cin >> X;
        if (X & 1) o++;
        else e++;
    }
    if ((o && e) || (o && (n & 1))) cout << "YES\n";
    else cout << "NO\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--) solve ();
}

