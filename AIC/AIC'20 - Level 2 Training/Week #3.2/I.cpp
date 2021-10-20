//https://vjudge.net/contest/419723#problem/I
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
    ll n, ans;
    cin >> n;
    n = sqrtl (n);
    for (ll i = 2; i * i <= n; ++i) while (n % i == 0) ans = i, n /= i;
    ans = (n > 1 ? n : ans);
    cout << ans;
}

