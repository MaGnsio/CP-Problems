//https://codeforces.com/contest/1514/problem/A
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        bool ok = false;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            int q = sqrt (x);
            if (q * q != x) {
                ok = true;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}

