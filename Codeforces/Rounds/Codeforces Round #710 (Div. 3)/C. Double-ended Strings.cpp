//https://codeforces.com/contest/1506/problem/C
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
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        int ans = a.size () + b.size (), chk = 0;
        for (int i = min (a.size (), b.size ()); i >= 1; --i)
        {
            size_t sz = i;
            for (int j = 0; j + i - 1 < a.size (); ++j)
            {
                for (int k = 0; k + i - 1 < b.size (); ++k)
                {
                    if (a.substr (j, sz) == b.substr (k, sz))
                    {
                        ans = (a.size () + b.size () - 2 * i);
                        chk = 1;
                        break;
                    }
                }
                if (chk) break;
            }
            if (chk) break;
        }
        cout << ans << "\n";
    }
}

