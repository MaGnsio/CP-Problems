//https://codeforces.com/problemset/problem/267/A
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
        ll a, b, cnt = 0;
        cin >> a >> b;
        while (a && b)
        {
            if (a < b) swap (a, b);
            cnt += a / b;
            a = a % b;
        }
        cout << cnt << "\n";
    }
}

