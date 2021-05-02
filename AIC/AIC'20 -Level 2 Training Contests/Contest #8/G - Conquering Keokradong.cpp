//https://vjudge.net/contest/433801#problem/G
#include <bits/stdc++.h>
using namespace std;

bool OK (int& M, int& K, vector<int>& V) {
    int cnt = 1, cur = 0;
    for (int i = 0; i < V.size(); ++i) {
        if (cur + V[i] > M) {
            cur = V[i];
            cnt++;
        } else {
            cur += V[i];
        }
    }
    return (cnt <= K);
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int Cases;
    cin >> Cases;
    for (int Case = 1; Case <= Cases; ++Case) {
        int N, K, L = -1, R = 0, X;
        cin >> N >> K;
        N++, K++;
        vector<int> V(N);
        for (int i = 0; i < N; ++i) {
            cin >> V[i];
            L = max(L, V[i]);
            R += V[i];
        }
        while (L <= R) {
            int M = (L + R) / 2;
            if (OK(M, K, V)) {
                X = M;
                R = M - 1;
            } else {
                L = M + 1;
            }
        }
        cout << "Case " << Case << ": " << X << "\n";
        int cnt = K, cur = 0;
        for (int i = 0; i < N; ++i) {
            if (cur + V[i] > X || N - i + 1 == cnt) {
                cout << cur << "\n";
                cur = V[i];
                cnt--;
            } else {
                cur += V[i];
            }
        }
        cout << cur << "\n";
    }
}
