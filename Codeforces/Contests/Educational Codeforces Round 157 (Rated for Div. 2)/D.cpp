/**
 *    author:  MaGnsi0
 *    created: 24.11.2023 15:07:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        a[i] ^= a[i - 1];
    }
    vector<array<int, 2>> T(1, {-1, -1});
    function<void(int)> insert = [&](int x) {
        for (int j = 0, b = 20; b >= 0; --b) {
            int k = x >> b & 1;
            if (T[j][k] == -1) {
                T[j][k] = (int)T.size();
                T.emplace_back(array<int, 2>{-1, -1});
            }
            j = T[j][k];
        }
    };
    function<int(int)> xorMax = [&](int x) {
        int ans = 0;
        for (int j = 0, b = 20; b >= 0; --b) {
            int k = x >> b & 1;
            if (T[j][k ^ 1] != -1) {
                ans |= 1 << b;
                j = T[j][k ^ 1];
            } else {
                j = T[j][k];
            }
        }
        return ans;
    };
    for (int i = 0; i < n; ++i) {
        insert(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (xorMax(i) == n - 1) {
            for (int j = 0; j < n; ++j) {
                a[j] ^= i;
            }
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
}
