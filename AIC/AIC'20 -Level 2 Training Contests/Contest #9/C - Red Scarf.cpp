//https://vjudge.net/contest/435043#problem/C
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long n;
    cin >> n;
    vector<long long> v(n), pre(n), suf(n);
    for (auto& x : v) {
        cin >> x;
    }
    pre[0] = v[0], suf[n - 1] = v[n - 1];
    for (int i = 1; i < n; ++i) {
        pre[i] = (pre[i - 1] ^ v[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
        suf[i] = (suf[i + 1] ^ v[i]);
    }
    for (int i = 0; i < n; ++i) {
        cout << ((i ? pre[i - 1] : 0) ^ (i < n - 1 ? suf[i + 1] : 0)) << " ";
    }
}

