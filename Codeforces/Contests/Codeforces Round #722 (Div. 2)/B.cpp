//https://codeforces.com/contest/1529/problem/B
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A, B;
        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
            if (x > 0) {
                A.push_back(x);
            } else {
                B.push_back(x);
            }
        }
        sort(B.begin(), B.end());
        int ANS = B.size(), mini = INT_MAX;
        for (int i = 1; i < B.size(); ++i) {
            mini = min(mini, B[i] - B[i - 1]);
        }
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] <= mini) {
                ANS++;
                break;
            }
        }
        cout << ANS << "\n";
    }
}
