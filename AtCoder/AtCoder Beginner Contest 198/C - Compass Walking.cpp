//https://atcoder.jp/contests/abc198/tasks/abc198_c
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long double R, X, Y;
    cin >> R >> X >> Y;
    long double D = sqrt ((X * X) + (Y * Y));
    if (D == R) {
        cout << 1;
    }
    else if (D <= 2 * R) {
        cout << 2;
    }
    else {
        cout << ceil (D / R);
    }
}

