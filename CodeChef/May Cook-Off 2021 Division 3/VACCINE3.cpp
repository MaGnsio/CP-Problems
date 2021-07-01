//https://www.codechef.com/COOK129C/problems/VACCINE3
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int G, P;
        vector<int> A(10);
        cin >> G >> P;
        for (auto& a : A) {
            cin >> a;
        }
        int before = 0;
        for (int i = 9; i > G - 1; --i) {
            before += A[i];
        }
        cout << (before / P) + 1 << " " << ((before + A[G - 1] - 1) / P) + 1 << "\n";
    }
}
