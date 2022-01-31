/**
 *    author:  MaGnsi0
 *    created: 24.01.2022 04:23:25
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> segmented_seive() {
    vector<int> P;
    vector<bool> isP(N, true);
    isP[0] = isP[1] = false;
    for (int i = 2; i < N; ++i) {
        if (isP[i]) {
            for (int j = 2 * i; j < N; j += i) {
                isP[j] = false;
            }
            P.push_back(i);
        }
    }
    return P;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> primes = segmented_seive();
    int T;
    cin >> T;
    while (T--) {
        int l, r;
        cin >> l >> r;
        int n = r - l + 1;
        vector<bool> isP(n, true);
        for (int i = 0; i < (int)primes.size(); ++i) {
            int x = max(2, ((l + primes[i] - 1) / primes[i]));
            for (int j = x * primes[i]; j <= r; j += primes[i]) {
                isP[j - l] = false;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (isP[i] && l + i > 1) {
                cout << l + i << "\n";
            }
        }
        cout << "\n";
    }
}
