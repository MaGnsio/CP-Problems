/**
 *    author:  MaGnsi0
 *    created: 03.04.2023 22:30:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        a[i] += a[i - 1];
    }
    int start = 0, end = n - 1;
    for (int i = 0; i < d; ++i) {
        int x;
        cin >> x;
        int L = a[x + start - 1] - (start ? a[start - 1] : 0);
        int R = a[end] - a[x + start - 1];
        if (L < R) {
            end = x + start - 1;
        } else {
            start = x + start;
        }
        cout << max(L, R) << "\n";
    }
}
