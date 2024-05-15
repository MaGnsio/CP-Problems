/**
 *    author:  MaGnsi0
 *    created: 13.05.2024 19:29:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n), I(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    iota(I.begin(), I.end(), 0);
    sort(I.begin(), I.end(), [&](int i, int j) {
            return a[i] < a[j];
        });
    vector<int> ansx(n), ansy(n), ans(n, -1);
    ansx[I[0]] = 1, ansy[I[0]] = 1;
    map<int, int> sum;
    for (int r = 2, j = 1; r <= n; ++r, ++j) {
        int i = I[j];
        if (a[i] == 0) {
            ansx[i] = r, ansy[i] = 1, ans[i] = i, sum[r + 1] = i + 1;
            continue;
        }
        int c = a[i] - r + 2;
        if (c <= 0) {
            int s = a[i] + r + 1;
            if (sum[s] == 0) {
                cout << "NO";
                return 0;
            }
            ansx[i] = r, ansy[i] = 1, ans[i] = sum[s], sum[r + 1] = i + 1;
        } else {
            ansx[i] = r, ansy[i] = c, ans[i] = 1, sum[r + c] = i + 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        int i1 = I[0], i2 = I[i];
        if (abs(ansx[i1] - ansx[i2]) + abs(ansy[i1] - ansy[i2]) == a[i1]) {
            ans[i1] = i2 + 1;
        }
    }
    if (ans[I[0]] == -1) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ansx[i] << " " << ansy[i] << "\n";
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}
