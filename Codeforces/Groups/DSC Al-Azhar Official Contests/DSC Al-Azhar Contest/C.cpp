//https://codeforces.com/group/iryj9wI6zY/contest/323491/problem/C
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    double h, r;
    cin >> h >> r;
    double l = sqrt ((h * h) + (r * r));
    double R = r * sqrt ((l - r) / (l + r));
    double volume = 4 * 3.14159265 * R * R * R / 3;
    cout << fixed << setprecision (6) << volume;
}

