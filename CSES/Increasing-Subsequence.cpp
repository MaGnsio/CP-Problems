/**
 *    author:  MaGnsi0
 *    created: 06.01.2022 16:45:47
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
int LIS(vector<T>& A) {
    int n = A.size(), k = 0;
    vector<int> memo(n, 0);
    vector<T> L(n, 0);
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
        L[pos] = A[i];
        if (pos == k) {
            k++;
        }
        memo[i] = pos + 1;
    }
    return k;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << LIS(a);
}
