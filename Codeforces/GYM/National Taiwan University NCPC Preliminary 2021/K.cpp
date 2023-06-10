/**
 *    author:  MaGnsi0
 *    created: 08.04.2023 03:07:13
**/
#include <bits/stdc++.h>

using namespace std;

int64_t F(int64_t k, int64_t x) {
    int64_t grundy = 0;
    while (x) {
        x /= k;
        grundy++;
    }
    return grundy - 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    map<int64_t, int> b;
    for (int i = 0; i < n; ++i) {
        int64_t grundy = F(a[0], a[i]), R = a[0];
        while (R > 1) {
            int64_t low = 2, high = R - 1, L = 1, new_grundy;
            while (low <= high) {
                int64_t mid = (low + high) / 2; 
                int64_t x = F(mid, a[i]);
                if (x > grundy) {
                    low = mid + 1;
                    L = mid, new_grundy = x;
                } else {
                    assert(x == grundy);
                    high = mid - 1;
                }
            }
            b[L + 1] ^= grundy, b[R + 1] ^= grundy;
            R = L, grundy = new_grundy;
        }
    }
    b.erase(b.find(b.rbegin() -> first));
    int xor_sum = 0;
    for (auto& [_, x] : b) {
        xor_sum ^= x;
        if (xor_sum == 0) {
            cout << "Bob";
            return 0;
        }
    }
    cout << "Alice";
}
