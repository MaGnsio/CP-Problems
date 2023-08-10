/**
 *    author:  MaGnsi0
 *    created: 19.06.2023 19:56:33
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> lpf(N);
    iota(lpf.begin(), lpf.end(), 0);
    for (int i = 2; i < N; ++i) {
        if (lpf[i] != i) { continue; }
        for (int j = 2 * i; j < N; j += i) {
            lpf[j] = min(lpf[j], i);
        }
    }
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n, -1), c(n, -1);
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        vector<int> p;
        while (x > 1) {
            p.push_back(lpf[x]);
            x /= lpf[x];
        }
        p.resize(unique(p.begin(), p.end()) - p.begin());
        int m = (int)p.size();
        for (int j = 0; j < m; ++j) {
            for (int k = j + 1; k < m; ++k) {
                if (__gcd(a[i], p[j] + p[k]) == 1) {
                    b[i] = p[j], c[i] = p[k];
                }
            }
        }
        for (int j = 0; j < m; ++j) {
            for (int k = j + 1; k < m; ++k) {
                for (int l = k + 1; l < m; ++l) {
                    if (__gcd(a[i], p[j] * p[k] + p[l]) == 1) {
                        b[i] = p[j] * p[k], c[i] = p[l];
                    }
                    if (__gcd(a[i], p[j] * p[l] + p[k]) == 1) {
                        b[i] = p[j] * p[l], c[i] = p[k];
                    }
                    if (__gcd(a[i], p[k] * p[l] + p[j]) == 1) {
                        b[i] = p[k] * p[l], c[i] = p[j];
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        cout << c[i] << " ";
    }
}
