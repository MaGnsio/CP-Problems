/**
 *    author:  MaGnsi0
 *    created: 05.01.2022 21:24:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), c(n, n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        multiset<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(-a[i]);
        }
        vector<long long> b(n + 1, -1);
        b[n] = 0;
        for (int i = 0; i < n; ++i) {
            if (s.lower_bound(-i) == s.end()) {
                b[i] = 0, b[n] = -1;
                break;
            }
            int x = (*s.lower_bound(-i));
            b[i] = (long long)i + x, c[i] = -x;
            s.erase(s.find(x));
        }
        for (int i = 1; i < n; ++i) {
            if (b[i] == -1) {
                break;
            }
            b[i] += b[i - 1];
        }
        vector<int> f(n + 2, 0);
        for (int i = 0; i < n; ++i) {
            f[c[i]]++;
        }
        for (int i = 0; i <= n; ++i) {
            if (b[i] == -1) {
                cout << b[i] << " ";
            } else {
                cout << (i ? b[i - 1] : 0LL) + f[i] << " ";
                if (i < n) {
                    f[c[i]]--;
                }
            }
        }
        cout << "\n";
    }
}
