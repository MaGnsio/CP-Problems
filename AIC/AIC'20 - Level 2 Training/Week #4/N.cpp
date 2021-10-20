//https://vjudge.net/contest/433102#problem/N
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        int n, k = -1;
        cin >> n;
        vector<int> v(n), f(1024, 0);
        for (auto& x : v) {
            cin >> x;
            f[x]++;
        }
        for (int i = 1; i < 1024; ++i) {
            bool chk = true;
            for (int j = 0; j < n; ++j) {
                if (!(f[v[j] ^ i])) {
                    chk = false;
                    break;
                }
            }
            if (chk) {
                k = i;
                break;
            }
        }
        cout << k << "\n";
    }
}

