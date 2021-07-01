//https://www.codechef.com/problems/STABLEMP
#include <bits/stdc++.h>
using namespace std;

int getIndex(vector<int> W, int m) {
    int i;
    for (i = 1; i < W.size(); ++i) {
        if (W[i] == m) {
            return i;
        }
    }
    return i;
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> M(N + 1, vector<int>(N + 1)), W(N + 1, vector<int>(N + 1));
        for (int i = 1; i <= N; ++i) {
            int x;
            cin >> x;
            for (int j = 1; j <= N; ++j) {
                cin >> W[x][j];
            }
        }
        for (int i = 1; i <= N; ++i) {
            int x;
            cin >> x;
            for (int j = 1; j <= N; ++j) {
                cin >> M[x][j];
            }
        }
        vector<int> S(N), WM(N + 1, -1), I(N + 1, 1);
        iota(S.begin(), S.end(), 1);
        while (!S.empty()) {
            int m = S[0];
            int w = M[m][I[m]];
            I[m]++;
            if (WM[w] == -1) {
                WM[w] = m;
                S.erase(S.begin());
            } else {
                if (getIndex(W[w], m) < getIndex(W[w], WM[w])) {
                    S.push_back(WM[w]);
                    WM[w] = m;
                    S.erase(S.begin());
                }
            }
        }
        vector<int> MW(N + 1);
        for (int i = 1; i <= N; ++i) {
            MW[WM[i]] = i;
        }
        for (int i = 1; i <= N; ++i) {
            cout << i << " " << MW[i] << "\n";
        }
    }
}
