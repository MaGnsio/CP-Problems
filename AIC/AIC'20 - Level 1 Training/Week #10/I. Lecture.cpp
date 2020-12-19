//https://codeforces.com/group/Rv2Qzg0DgK/contest/290492/problem/I
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
    int n, m;
    string x, y;
    map<string, string> M;
    cin >> n >> m;
    while (m--)
    {
        cin >> x >> y;
        if (x.size () <= y.size ()) M[x] = x;
        else M[x] = y;
    }
    while (n--)
    {
        cin >> x;
        cout << M[x] << " ";
    }
}

