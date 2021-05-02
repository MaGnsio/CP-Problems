//https://codeforces.com/group/aDFQm4ed6d/contest/279152/problem/C
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

bool islucky (int x)
{
    while (x)
    {
        if (x % 10 != 4 && x % 10 != 7) return false;
        x /= 10;
    }
    return true;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    vector<int> lucky;
    for (int i = 4; i <= 1000; ++i) if (islucky (i)) lucky.push_back (i);
    int x;
    cin >> x;
    for (int i = 0; i < lucky.size (); ++i) if (x % lucky[i] == 0) return cout << "YES", 0;
    cout << "NO";
}

