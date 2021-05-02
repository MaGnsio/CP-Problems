//https://codeforces.com/contest/1260/problem/A
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
    while (n--)
    {
        ll c, s;
        cin >> c >> s;
        ll ans = (c - (s % c)) * (s / c) * (s / c) + ((s % c) * (s / c + 1) * (s / c + 1));
        cout << ans << "\n";
    }
}
