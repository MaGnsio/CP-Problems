//https://codeforces.com/group/Rv2Qzg0DgK/contest/290492/problem/T
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
    int n, q;
    list<string> l;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        string x;
        cin >> x;
        l.push_back (x);
    }
    for (int i = 0; i < q; ++i)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            string y;
            cin >> y;
            bool chk = true;
            for (auto it = l.begin (); it != l.end (); ++it) if (*it == y)
            {
                l.erase (it);
                chk = false;
                break;
            }
            if (chk) cout << "Not found\n";
        }
        else if (x == 2)
        {
            if (l.empty ())
            {
                cout << 0 << "\n";
                continue;
            }
            for (auto it = l.begin (); it != l.end (); ++it) cout << *it << " ";
            cout << "\n";
        }
        else
        {
            if (l.empty ())
            {
                cout << 0 << "\n";
                continue;
            }
            for (auto it = l.rbegin (); it != l.rend (); ++it) cout << *it << " ";
            cout << "\n";
        }
    }
}

