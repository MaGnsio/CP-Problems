//https://vjudge.net/contest/434102#problem/C
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;


long long product (long long n, long long m) {
    if (n > m) {
        return product (m, n);
    }
    if (m == 0) {
        return 0;
    }
    long long temp = product (n, m / 2);
    long long res = (temp % mod + temp % mod) % mod;
    if (m & 1) {
        res = (res % mod + n % mod) % mod;
    }
    return res;
}

long long power (long long b, long long p) {
    if (p == 0) {
        return 1;
    }
    long long temp = power (b, p / 2);
    long long res = product (temp, temp);
    if (p & 1) {
        res = product (res, b);
    }
    return res;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long n, m;
    cin >> n >> m;
    cout << power (n, m);
}

