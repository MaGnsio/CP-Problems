//https://atcoder.jp/contests/abc183/tasks/abc183_b
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
    double Sx, Sy, Gx, Gy;
    cin >> Sx >> Sy >> Gx >> Gy;
    double X = (Sy * Gx + Gy * Sx) / (Sy + Gy);
    cout << fixed << setprecision (10) << X;
}

