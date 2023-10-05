//https://codeforces.com/contest/1487/problem/B
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
        ll n, k;
        cin >> n >> k;
        k--;
        ll ans = (k + ((k / (n / 2)) * (n % 2))) % n + 1;
        cout << ans << "\n";
    }
}

