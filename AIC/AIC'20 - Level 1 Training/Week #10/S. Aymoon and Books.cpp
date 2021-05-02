//https://codeforces.com/group/Rv2Qzg0DgK/contest/290492/problem/S
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
    deque<int> s;
    priority_queue<int> t;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        s.push_back (x);
    }
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        char x;
        cin >> x;
        if (x == 'L')
        {
            if (s.empty ()) continue;
            t.push (s.front ());
            s.pop_front ();
        }
        else if (x == 'R')
        {
            if (s.empty ()) continue;
            t.push (s.back ());
            s.pop_back ();
        }
        else
        {
            if (t.empty ())
            {
                cout << -1 << "\n";
                continue;
            }
            cout << t.top () << "\n";
            t.pop ();
        }
    }
}

