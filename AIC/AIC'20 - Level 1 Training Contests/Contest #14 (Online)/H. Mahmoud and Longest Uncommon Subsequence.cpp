//https://codeforces.com/group/aDFQm4ed6d/contest/287062/problem/H
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
    string x, y;
    cin >> x >> y;
    cout << (x != y ? int (max (x.size (), y.size ())) : -1);
}

