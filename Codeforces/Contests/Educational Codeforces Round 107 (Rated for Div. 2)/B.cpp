//https://codeforces.com/contest/1511/problem/B
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int x = 1, y = 1, z = 1;
        while (to_string (z).size () != c) {
            z *= 2;
        }
        x = y = z;
        while (to_string (x).size () != a) {
            x *= 3;
        }
        while (to_string (y).size () != b) {
            y *= 5;
        }
        cout << x << " " << y << "\n";
    }
}

