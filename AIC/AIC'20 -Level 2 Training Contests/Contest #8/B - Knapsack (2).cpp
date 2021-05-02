//https://vjudge.net/contest/433801#problem/B
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long n, l, r, k;
    cin >> n;
    vector<long long> w(n), v(n), ans;
    for (long long i = 0; i < n; ++i) {
        cin >> w[i] >> v[i];
    }
    cin >> l >> r >> k;
    for (long long mask = 0; mask < (1LL << n); ++mask) {
        bool chk = true;
        long long V = 0;
        for (long long i = 0; i < n; ++i) {
            if ((1LL << i) & mask) {
                if (w[i] >= l && w[i] <= r) {
                    V += v[i];
                }
                else {
                    chk = false;
                    break;
                }
            }
        }
        if (chk) {
            ans.push_back (V);
        }
    }
    sort (ans.begin (), ans.end ());
    cout << (ans.size () < k ? -1 : ans[k - 1]) << "\n";
}
