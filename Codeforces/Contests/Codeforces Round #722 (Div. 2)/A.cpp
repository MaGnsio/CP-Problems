//https://codeforces.com/contest/1529/problem/A
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
        cout << N - count(V.begin(), V.end(), *min_element(V.begin(), V.end())) << "\n";
    }

}
