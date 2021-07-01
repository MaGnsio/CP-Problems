//https://vjudge.net/contest/372876#problem/A
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> V(N, 0);
        cin.ignore();
        for (int i = 0; i < N; ++i) {
            string s;
            getline(cin, s);
            V[i] += count(s.begin(), s.end(), ' ') + 1;
        }
        int X = *min_element(V.begin(), V.end());
        for (int i = 0, j = 0; i < N; ++i) {
            if (V[i] == X) {
                cout << (j != 0 ? " " : "") << i + 1;
                j++;
            }
        }
        cout << "\n";
    }
}

