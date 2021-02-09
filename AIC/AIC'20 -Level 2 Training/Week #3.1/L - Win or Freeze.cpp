//https://vjudge.net/contest/419722#problem/L
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
    ll q, cnt = 0, f = 1;
    cin >> q;
    for (ll i = 2; (i * i <= q) && (cnt != 2); ++i)
    {
        while (q % i == 0 && cnt != 2) q /= i, cnt += 1, f *= i;
    }
    if (cnt == 0) cout << "1\n0";
    else if (cnt == 2 && q != 1) cout << "1\n" << f;
    else cout << 2;
}

