//https://vjudge.net/contest/417978#problem/I
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
    ll Z, O;
    cin >> Z >> O;
    if (!((O >= Z - 1) && ((O - 1) / 2 <= Z))) return cout << -1, 0;
    ll cur1 = 0;
    if (Z > O)
    {
        cout << 0;
        Z--;
    }
    while (O + Z)
    {
        if (cur1 == 0 && O)
        {
            cout << 1;
            cur1++;
            O--;
        }
        else if (cur1 == 1 && O && O > Z)
        {
            cout << 1;
            cur1++;
            O--;
        }
        else
        {
            cout << 0;
            cur1 = 0;
            Z--;
        }
    }
}

