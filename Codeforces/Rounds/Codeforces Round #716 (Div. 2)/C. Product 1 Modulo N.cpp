//https://codeforces.com/contest/1514/problem/C
#include <bits/stdc++.h>
using namespace std;

bool f[100005];

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    long long res = 1;
    for (int i = 1; i < n; ++i) {
        if (gcd (i, n) == 1) {
            f[i] = 1;
            res = (res * i) % n;
        }
    }
    if (res != 1) {
        f[res] = 0;
    }
    cout << count (f, f + n, true) << "\n";
    for (int i = 1; i < n; ++i) {
        if (f[i]) {
            cout << i << " ";
        }
    }
}

