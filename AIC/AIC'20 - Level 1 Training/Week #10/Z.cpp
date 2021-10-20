//https://codeforces.com/group/Rv2Qzg0DgK/contest/290492/problem/Z
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, sz = 1e5 + 10;
int a[sz], x[sz], p[sz];

struct compare
{
    bool operator() (const int x, const int y) const
    {
        if (a[x] == a[y]) return x < y;
        return a[x] > a[y];
    }
};

set<int, compare> s;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--)
    {
        s.clear ();
        int n, q, mx = INT_MIN, idx = -1;
        cin >> n >> q;
        memset (a, 0, sizeof (a));
        for (int i = 1; i <= q; ++i)
        {
            cin >> x[i] >> p[i];
            a[x[i]] += p[i];
        }
        for (int i = 1; i <= n; ++i) if (a[i] > mx)
        {
            mx = a[i];
            idx = i;
        }
        memset (a, 0, sizeof (a));
        for (int i = 1; i <= n; ++i) s.insert (i);
        int pos = (*s.begin () != idx ? 1 : 0);
        for (int i = 1; i <= q; ++i)
        {
            s.erase (x[i]);
            a[x[i]] += p[i];
            s.insert (x[i]);
            if (*s.begin () != idx) pos = i + 1;
        }
        cout << pos << "\n";
    }
}

