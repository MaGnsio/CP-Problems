//https://codeforces.com/contest/1512/problem/G
#include <bits/stdc++.h>
using namespace std;
const long long sz = 1e7 + 5;
vector<long long> d(sz, 1), ans(sz, -1);

void init () {
    for (long long i = 2; i < sz; ++i) {
        for (long long j = i; j < sz; j += i) {
            d[j] += i;
        }
    }
    for (long long i = 1; i < sz; ++i) {
        if (d[i] < sz && ans[d[i]] == -1) {
            ans[d[i]] = i;
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    init ();
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << ans[n] << "\n";
    }
}

