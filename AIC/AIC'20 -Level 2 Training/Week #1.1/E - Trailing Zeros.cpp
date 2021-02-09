//https://vjudge.net/contest/416230#problem/E
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
    ll n, ans = 0;
    cin >> n;
    for (ll i = 5; n / i >= 1; i *= 5) ans += n / i;
    cout << ans;
}

