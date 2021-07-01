//https://vjudge.net/contest/372876#problem/B
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int N, M, ok = 1;
        cin >> N >> M;
        vector<int> V(M, 0);
        vector<set<int>> S(M);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int x;
                cin >> x;
                if (x) {
                    V[j]++;
                    S[j].insert(i);
                }
            }
        }
        for (int i = 0; i < M; ++i) {
            if (V[i] != 2) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            sort(S.begin(), S.end());
            for (int i = 1; i < M; ++i) {
                if (S[i] == S[i - 1]) {
                    ok = 0;
                    break;
                }
            }
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
}

