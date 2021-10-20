//https://vjudge.net/contest/435043#problem/F
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long n, m, p;
    cin >> n >> m >> p;
    long long x, y;
    for (long long i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        if (a % p) {
            x = i;
        }
    }
    for (long long i = 0; i < m; ++i) {
        long long a;
        cin >> a;
        if (a % p) {
            y = i;
        }
    }
    cout << x + y;
}

