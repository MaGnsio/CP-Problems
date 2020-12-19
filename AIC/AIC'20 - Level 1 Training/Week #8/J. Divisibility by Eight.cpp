//https://codeforces.com/group/Rv2Qzg0DgK/contest/286457/problem/J
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
    string s;
    cin >> s;
    for (int i = s.size () - 1; i >= 0 && s.size () > 0; --i)
    {
        if ((s[i] - '0') % 8 == 0)
        {
            cout << "YES\n" << s[i] - '0';
            return 0;
        }
    }
    for (int i = s.size () - 1; i >= 1 && s.size () > 1; --i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (((s[i] - '0') + ((s[j] - '0') * 10)) % 8 == 0)
            {
                cout << "YES\n" << (s[i] - '0') + ((s[j] - '0') * 10);
                return 0;
            }
        }
    }
    for (int i = s.size () - 1; i >= 2 && s.size () > 2; --i)
    {
        for (int j = i - 1; j >= 1; --j)
        {
            for (int k = j - 1; k >= 0; --k)
            {
                if (((s[i] - '0') + ((s[j] - '0') * 10) + ((s[k] - '0') * 100)) % 8 == 0)
                {
                    cout << "YES\n" << (s[i] - '0') + ((s[j] - '0') * 10) + ((s[k] - '0') * 100);
                    return 0;
                }
            }
        }
    }
    cout << "NO";
}

