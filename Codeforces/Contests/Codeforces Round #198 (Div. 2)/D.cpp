/**
 *    author:  MaGnsi0
 *    created: 21/09/2021 00:43:57
**/
#include <bits/stdc++.h>
using namespace std;

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
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> dp(n);
    LIS<int>(v, dp);
    cout << *max_element(dp.begin(), dp.end());
}
