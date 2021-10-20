//https://vjudge.net/contest/419722#problem/U
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
    ll a, b;
    while ((cin >> a >> b) && (a || b))
    {
        ll cnt = 0;
        if (a < b) swap (a, b);
        while (!(a % b == 0 || a / b > 1))
        {
            a = a % b;
            swap (a, b);
            cnt++;
        }
        cout << (cnt & 1 ? "Ollie wins\n" : "Stan wins\n");
    }
}

