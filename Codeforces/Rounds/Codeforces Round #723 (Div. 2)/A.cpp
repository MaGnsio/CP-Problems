//https://codeforces.com/contest/1526/problem/A
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> V(2 * N);
        for (int i = 0; i < 2 * N; ++i) {
            cin >> V[i];
        }
        sort(V.begin(), V.end());
        for (int i = 0; i < N; ++i) {
            cout << V[i] << " " << V[2 * N - i - 1] << " ";
        }
        cout << "\n";
    }
}
