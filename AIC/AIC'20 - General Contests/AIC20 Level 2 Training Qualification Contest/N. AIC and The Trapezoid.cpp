//https://codeforces.com/group/nVgev28wQI/contest/308101/problem/N
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
    ld a, b, h;
    cin >> a >> b >> h;
    ld area = (a + b) * h / 2;
    cout << fixed << setprecision (6) << area;
}

