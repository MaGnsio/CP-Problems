//https://codeforces.com/problemset/problem/1343/B
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void solve ()
{
    ll n;
    cin >> n;
    if (n % 4 != 0)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (ll i = 2, j = 0; j < n / 2; i += 2, j++) cout << i << " ";
    for (ll i = 1, j = 0; j < n / 2; i += 2, j++) cout << (j == n / 2 - 1 ? i + n / 2 : i) << " ";
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

