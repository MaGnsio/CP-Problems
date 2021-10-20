//https://vjudge.net/contest/416254#problem/E
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
    ll a[8];
    for (auto& elem : a) cin >> elem;
    if ((a[0] - a[2]) * (a[5] - a[7]) == (a[1] - a[3]) * (a[4] - a[6])) cout << "YES";
    else cout << "NO";
}

