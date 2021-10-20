//https://codeforces.com/group/aDFQm4ed6d/contest/296501/problem/D
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
    int r, c;
    int a[5][5];
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin >> a[i][j];
            if (a[i][j]) r = i + 1, c = j + 1;
        }
    }
    cout << abs (3 - r) + abs (3 - c);
}

