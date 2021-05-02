//https://vjudge.net/contest/434102#problem/L
#include <bits/stdc++.h>
using namespace std;

long long solve (long long x) {
    if (x == 1) {
        return 0;
    }
    if (x & (x - 1)) {
        long long temp = x, cnt = -1;
        while (temp) {
            temp /= 2;
            cnt++;
        }
        return 1 + solve (x - (1LL << cnt));
    } else {
        return 1 + solve (x / 2);
    }
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        cout << (solve (k) & 1 ? 1 : 0) << "\n";
    }
}

