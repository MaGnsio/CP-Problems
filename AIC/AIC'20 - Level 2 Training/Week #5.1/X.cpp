//https://vjudge.net/contest/434102#problem/X
#include <bits/stdc++.h>
using namespace std;

long long solve (long long n, long long k, long long a, long long b, vector<long long>& v, long long s, long long e) {
    long long m = upper_bound (v.begin (), v.end (), e) - lower_bound (v.begin(), v.end(), s);
    long long l = e - s + 1;
    long long x = (m ? l * m * b : a);
    long long mid = (s + e) / 2;
    if (s == e || m == 0) {
        return x;
    }
    return min (x, solve (n, k, a, b, v, s, mid) + solve (n, k, a, b, v, mid + 1, e));
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long n, k, a, b;
    cin >> n >> k >> a >> b;
    vector<long long> v (k);
    for (auto& x : v) {
        cin >> x;
    }
    sort (v.begin (), v.end ());
    cout << solve (n, k, a, b, v, 1LL, (1LL << n));
}

