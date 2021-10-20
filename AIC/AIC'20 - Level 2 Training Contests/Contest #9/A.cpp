//https://vjudge.net/contest/435043#problem/A
#include <bits/stdc++.h>
using namespace std;

void solve(int N, int M, int H, int& T, vector<int>& R, vector<int>& L, int D = 1, int temp = 0, int x = 0) {
    int k, l, r;
    if (D) {
        k = R[x];
        l = k;
        r = M + 1 - k;
    } else {
        k = L[x];
        l = M + 1 - k;
        r = k;
    }
    if (x == H) {
        T = min(T, temp + k);
        return;
    }
    solve(N, M, H, T, R, L, 1, temp + k + l + 1, x + 1);
    solve(N, M, H, T, R, L, 0, temp + k + r + 1, x + 1);
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M, T = INT_MAX, H = -1;
    cin >> N >> M;
    vector<int> R(N, 0), L(N, 0);
    for (int i = N - 1; i >= 0; --i) {
        string S;
        cin >> S;
        for (int j = 0; j < M + 2; ++j) {
            if (S[j] == '1') {
                R[i] = j;
                H = max(H, i);
            }
        }
        for (int j = M + 1; j >= 0; --j) {
            if (S[j] == '1') {
                L[i] = M + 1 - j;
                H = max(H, i);
            }
        }
    }
    if (H == -1) {
        cout << 0;
        return 0;
    }
    solve(N, M, H, T, R, L);
    cout << T;
}

