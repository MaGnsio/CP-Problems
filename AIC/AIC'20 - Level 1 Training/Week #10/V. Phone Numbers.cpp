//https://codeforces.com/group/Rv2Qzg0DgK/contest/290492/problem/V
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

bool comp (string a, string b) {return a.size () < b.size ();}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    map<string, vector<string>> m;
    for (ll i = 0; i < n; ++i)
    {
        int x;
        string s;
        cin >> s >> x;
        for (int j = 0; j < x; ++j)
        {
            string y;
            cin >> y;
            m[s].push_back (y);
        }
    }
    for (auto& x : m)
    {
        sort (x.S.begin (), x.S.end (), comp);
        for (int i = 0; i < x.S.size (); ++i)
        {
            for (int j = i + 1; j < x.S.size (); ++j)
            {
                string temp = x.S[j].substr (x.S[j].size () - x.S[i].size (), x.S[i].size ());
                if (temp == x.S[i])
                {
                    x.S.erase (x.S.begin () + i);
                    i--;
                    break;
                }
            }
        }
    }
    cout << m.size () << "\n";
    for (auto& x : m)
    {
        cout << x.F << " " << x.S.size () << " ";
        for (auto& y : x.S) cout << y << " ";
        cout << "\n";
    }
}

