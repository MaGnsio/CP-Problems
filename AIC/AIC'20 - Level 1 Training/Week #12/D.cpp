//https://codeforces.com/group/Rv2Qzg0DgK/contest/292431/problem/D
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
    ll a[n];
    for (auto& elem : a) cin >> elem;
    ll s = 0, e = n - 1, curr_max = max (abs (a[s]), abs(a[e])), ctr = 1;
    while (s <= e)
    {
        if (curr_max == abs (a[s]))
        {
            s++;
            continue;
        }
        if (curr_max == abs (a[e]))
        {
            e--;
            continue;
        }
        if (abs (a[s]) >= abs (a[e])) curr_max = abs (a[s++]);
        else curr_max = abs (a[e--]);
        ctr++;
    }
    cout << ctr;
}

