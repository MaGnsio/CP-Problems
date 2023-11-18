/**
 *    author:  MaGnsi0
 *    created: 24.10.2023 04:56:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int GL = 0, PL = 0;
    int GR = 0, PR = 0;
    char C, S = 'L', W = '?';
    while (cin >> C) {
        if (C == 'Q') {
            if (W == '?') {
                cout << GL << " (" << PL << (S == 'L' ? "*) - " : ") - ");
                cout << GR << " (" << PR << (S == 'R' ? "*)\n" : ")\n");
            } else {
                cout << GL << (W == 'L' ? " (winner) - " : " - ");
                cout << GR << (W == 'R' ? " (winner)\n" : "\n");
            }
        } else {
            if (C == 'S') {
                if (S == 'L') {
                    PL++;
                } else {
                    PR++;
                }
            } else {
                if (S == 'L') {
                    PR++;
                    S = 'R';
                } else {
                    PL++;
                    S = 'L';
                }
            }
            if ((PL >= 5 && PL - PR >= 2) || (PL == 10)) {
                GL++;
                PL = PR = 0;
            } else if ((PR >= 5 && PR - PL >= 2) || (PR == 10)) {
                GR++;
                PL = PR = 0;
            }
            if (GL == 2) { W = 'L'; }
            if (GR == 2) { W = 'R'; }
        }
    }
}
