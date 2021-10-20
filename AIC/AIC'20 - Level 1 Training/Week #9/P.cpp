//https://codeforces.com/group/Rv2Qzg0DgK/contest/287283/problem/P
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
    int x = 2, i = 1;
    string s;
    vector<string> v;
    while (cin >> s)
    {
        x = 2, i = 1;
        v.push_back ("*");
        for (auto& elem : s)
        {
            if (elem == '[') x = 1, i = 1;
            else if (elem == ']') x = 2;
            else if (x == 1)
            {
                v.back ().insert (v.back ().begin () + i, elem);
                i++;
            }
            else v.back ().push_back (elem);
        }
    }
    for (auto& elem : v) cout << elem.substr (1, elem.size () - 1) << "\n";
}
 
