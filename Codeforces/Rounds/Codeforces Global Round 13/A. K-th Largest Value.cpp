//https://codeforces.com/contest/1491/problem/A
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
    ll n, q, cnt = 0;
    cin >> n >> q;
    ll a[n];
    for (auto& x : a)
    {
        cin >> x;
        cnt += (x == 1);
    }
    while (q--)
    {
        ll x, i;
        cin >> x >> i;
        if (x == 1)
        {
            if (a[i - 1] == 1) cnt--;
            else cnt++;
            a[i - 1] = 1 - a[i - 1];
        }
        else cout << (i > cnt ? 0 : 1) << "\n";
    }
}

