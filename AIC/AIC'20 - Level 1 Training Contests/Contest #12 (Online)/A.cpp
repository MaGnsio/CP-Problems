//https://codeforces.com/group/aDFQm4ed6d/contest/279956/problem/A
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
    int a[4] = {};
    for (auto& x : s)
    {
        a[0] += (x == 'n');
        a[1] += (x == 'i');
        a[2] += (x == 'e');
        a[3] += (x == 't');
    }
    a[0] = max (a[0] - 1, 0);
    cout << min ({a[0] / 2, a[1], a[2] / 3, a[3]});
}

