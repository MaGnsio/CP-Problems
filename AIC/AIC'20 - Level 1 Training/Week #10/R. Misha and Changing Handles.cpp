//https://codeforces.com/group/Rv2Qzg0DgK/contest/290492/problem/R
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
    int q;
    cin >> q;
    unordered_map<string, string> m;
    for (int i = 0; i < q; ++i)
    {
        string o, n;
        cin >> o >> n;
        bool chk = true;
        if (m.find (o) == m.end ())
        {
            for (auto& x : m)
            {
                if (x.S == o)
                {
                    x.S = n;
                    chk = false;
                    break;
                }
            }
        }
        if (chk) m[o] = n;
    }
    cout << m.size () << "\n";
    for (auto& x : m) cout << x.F << " " << x.S << "\n";
}

