/**
 *    author:  MaGnsi0
 *    created: 04/06/2021 16:20:53
**/
#include <bits/stdc++.h>
using namespace std;

void seive(int& maxN, vector<bool>& isPrime, vector<int>& v) {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < maxN; ++i) {
        if (isPrime[i]) {
            for (int j = 2 * i; j < maxN; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i < maxN; ++i) {
        if (isPrime[i] && isPrime[(i + 1) / 2]) {
            v[i]++;
        }
    }
    for (int i = 1; i < maxN; ++i) {
        v[i] += v[i - 1];
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int maxN = 1e5 + 5;
    vector<int> v(maxN, 0);
    vector<bool> isPrime(maxN, true);
    seive(maxN, isPrime, v);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << v[r] - v[l - 1] << "\n";
    }
}
