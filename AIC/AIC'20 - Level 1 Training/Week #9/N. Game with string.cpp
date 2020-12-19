//https://codeforces.com/group/Rv2Qzg0DgK/contest/287283/problem/N
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
    int cnt = 0;
    string s;
    cin >> s;
    for (int i = 1; i < s.size (); ++i)
    {
        if (s[i] == s[i - 1])
        {
            cnt++;
            s.erase (i - 1, 2);
            i -= 2;
        }
    }
    if (cnt & 1) cout << "YES";
    else cout << "NO";
}

