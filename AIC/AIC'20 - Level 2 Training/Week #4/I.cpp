//https://vjudge.net/contest/433102#problem/I
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        int k, maxi = 0, cnt = 0;
        vector<int> v(11);
        for (auto& x : v) cin >> x;
        cin >> k;
        sort (v.begin (), v.end (), greater<int> ());
        for (int i = 0; i < k; ++i) {
            maxi += v[i];
        }
        for (int mask = 0; mask < (1 << 11); ++mask) {
            if (__builtin_popcount (mask) != k) {
                continue;
            }
            int score = 0;
            for (int j = 0; j < 11; ++j) {
                if ((1 << j) & mask) {
                    score += v[j];
                }
            }
            if (score == maxi) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}

