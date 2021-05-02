//https://codeforces.com/contest/1475/problem/B
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2020 <= n / 2020) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

