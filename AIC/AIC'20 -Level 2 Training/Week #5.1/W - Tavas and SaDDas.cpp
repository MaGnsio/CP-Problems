//https://vjudge.net/contest/434102#problem/W
#include <bits/stdc++.h>
using namespace std;

long long solve (long long n, long long cur = 0, long long i = 0) {
    if (cur > n) {
        return -1;
    }
    if (cur == n) {
        return i;
    }
    return max (solve (n, cur * 10 + 4, 2 * i + 1), solve (n, cur * 10 + 7, 2 * i + 2));
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long n;
    cin >> n;
    cout << solve (n);
}

