//https://codeforces.com/contest/1525/problem/B
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> V(N);
        for (int i = 0; i < N; ++i) {
            cin >> V[i];
        }
        bool sorted = true;
        for (int i = 1; i < N; ++i) {
            if (V[i] < V[i - 1]) {
                sorted = false;
            }
        }
        if (sorted) {
            cout << 0 << "\n";
        } else if (V[0] == N && V[N - 1] == 1) {
            cout << 3 << "\n";
        } else if (V[0] == 1 || V[N - 1] == N) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }
}
