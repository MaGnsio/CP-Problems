//https://vjudge.net/contest/416254#problem/J
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
    ll n;
    cin >> n;
    ld ans = (n / 3.0) * (n / 3.0) * (n / 3.0);
    cout << fixed << setprecision (6) << ans;
}

