//https://codeforces.com/group/aDFQm4ed6d/contest/279676/problem/C
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
    string s;
    cin >> s;
    for (int i = 0; i < s.size (); ++i)
    {
        if (!((s[i] == '1') || (s[i] == '4' && s[i - 1] == '1') || (s[i] == '4' && s[i -1] == '4' && s[i - 2] == '1')))
		{
			return cout << "NO", 0;
		}
    }
    cout << "YES";
}

