//https://codeforces.com/group/aDFQm4ed6d/contest/298276/problem/K
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, sz = 30;

void solve ()
{
    ll n;
    cin >> n;
    while (n--)
    {
        ll x;
        cin >> x;
        bitset<sz> b (x);
        cout << b.count () << " ";
    }
    cout << "\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
        solve ();
}

