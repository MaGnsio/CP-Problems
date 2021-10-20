//https://vjudge.net/contest/434102#problem/A
#include <bits/stdc++.h>
using namespace std;

int solve (int n) {
    if (n == 1) {
        return 1;
    }
    if (n & 1) {
        return 1 + solve (3 * n + 1);
    } else {
        return 1 + solve (n / 2);
    }
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    cout << solve (n);
}

