//https://atcoder.jp/contests/abc202/tasks/abc202_c
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    cin >> N;
    vector<int> A(N + 1, 0), C(N + 1, 0);
    vector<vector<int>> B(N + 1);
    for (int i = 1; i <= N; ++i) {
        int x;
        cin >> x;
        A[x]++;

    }
    for (int i = 1; i <= N; ++i) {
        int x;
        cin >> x;
        B[x].push_back(i);
    }
    for (int i = 1; i <= N; ++i) {
        int x;
        cin >> x;
        C[x]++;
    }
    long long cnt = 0;
    for (int i = 1; i <= N; ++i) {
        int x = 0;
        for (auto& b : B[i]) {
            x += C[b];
        }
        cnt += ((long long) x * (long long) A[i]);
    }
    cout << cnt;
}
