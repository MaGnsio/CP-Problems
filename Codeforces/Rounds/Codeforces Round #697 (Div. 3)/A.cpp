//https://codeforces.com/problemset/problem/1475/A
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        while (n % 2 == 0) n /= 2;
        cout << (n > 1 ? "YES\n" : "NO\n");
    }
}

