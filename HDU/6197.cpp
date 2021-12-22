/**
 *    author:  MaGnsi0
 *    created: 10.11.2021 21:50:47
**/
#include <bits/stdc++.h>

using namespace std;

//O(n log k) Greedy + D&C Algorithm
template <typename T>
void LIS(vector<T>& A, vector<int>& memo) {
    int n = A.size(), k = 0;
    vector<T> L(n, 0);
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
        L[pos] = A[i];
        if (pos == k) {
            k++;
        }
        memo[i] = pos + 1;
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> dp1(n, 0);
        LIS(a, dp1);
        for (int i = 0; i < n; ++i) {
            a[i] *= -1;
        }
        vector<int> dp2(n, 0);
        LIS(a, dp2);
        bool magic = false;
        for (int i = 0; i < n; ++i) {
            magic |= (dp1[i] >= n - k);
            magic |= (dp2[i] >= n - k);
        }
        cout << (magic ? "A is a magic array." : "A is not a magic array.") << "\n";
    }
}
