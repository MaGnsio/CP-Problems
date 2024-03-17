/**
 *    author:  MaGnsi0
 *    created: 23.12.2023 14:15:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<int64_t> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    for (int i = 1; i < N; ++i) {
        A[i] += A[i - 1];
    }
    while (Q--) {
        int64_t X; cin >> X;
        int low = 0, high = N - 1, ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] <= X) {
                ans = mid + 1;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}
