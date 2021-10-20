//https://vjudge.net/contest/435043#problem/D
#include <bits/stdc++.h>
using namespace std;

int solve (int n) {
    if (n == 1) {
        return 0;
    }
    if (n % 3 == 0 && n % 2 == 0) {
        return (1 + min({solve(n / 2), solve(n / 3), solve(n - 1)}));
    } else if (n % 3 == 0) {
        return (1 + min(solve(n / 3), solve(n - 1)));
    } else if (n % 2 == 0) {
        return (1 + min(solve(n / 2), solve(n - 1)));
    } else {
        return (1 + solve (n - 1));
    }
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    cout << solve (n);
}

