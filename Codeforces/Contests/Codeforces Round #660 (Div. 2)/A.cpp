//https://codeforces.com/problemset/problem/1388/A
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
        ll n, cnt = 0;
        cin >> n;
        if (n > 30)
        {
            cout << "YES\n";
            if (n - 30 == 6 || n - 30 == 10 || n - 30 == 14) cout << "6 10 15 " << n - 31 << "\n";
            else cout << "6 10 14 " << n - 30 << "\n";
        }
        else cout << "NO\n";
    }
}

