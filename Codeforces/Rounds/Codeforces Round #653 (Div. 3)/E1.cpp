/**
 *    author:  MaGnsi0
 *    created: 19.11.2021 22:55:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a, b, c;
    for (int i = 0; i < n; ++i) {
        int t, x, y;
        cin >> t >> x >> y;
        if (x && y) {
            c.push_back(t);
        } else if (y) {
            b.push_back(t);
        } else if (x) {
            a.push_back(t);
        }
    }
    if ((int)(a.size() + c.size()) < k || (int)(b.size() + c.size()) < k) {
        cout << -1;
        return 0;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    int nk = min({k, (int)a.size(), (int)b.size()});
    int sumA = accumulate(a.begin(), a.begin() + nk, 0);
    int sumB = accumulate(b.begin(), b.begin() + nk, 0);
    int sumC = (nk < k ? accumulate(c.begin(), c.begin() + k - nk, 0) : 0);
    for (int i = k - nk, j = nk - 1; i < (int)c.size() && j >= 0; ++i) {
        if (a[j] + b[j] > c[i]) {
            sumA -= a[j];
            sumB -= b[j];
            sumC += c[i];
            j--;
        }
    }
    cout << sumA + sumB + sumC;
}
