/**
 *    author:  MaGnsi0
 *    created: 04.08.2024 17:35:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        int A = count(s.begin(), s.end(), 'A'); A = min(A, n);
        int B = count(s.begin(), s.end(), 'B'); B = min(B, n);
        int C = count(s.begin(), s.end(), 'C'); C = min(C, n);
        int D = count(s.begin(), s.end(), 'D'); D = min(D, n);
        cout << A + B + C + D << "\n";
    }
}
