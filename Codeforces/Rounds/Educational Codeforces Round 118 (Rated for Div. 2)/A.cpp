/**
 *    author:  MaGnsi0
 *    created: 01.12.2021 16:24:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int x1, p1;
        cin >> x1 >> p1;
        int x2, p2;
        cin >> x2 >> p2;
        while (x1 % 10 == 0) {
            x1 /= 10;
            p1++;
        }
        while (x2 % 10 == 0) {
            x2 /= 10;
            p2++;
        }
        if (x1 == x2 && p1 == p2) {
            cout << "=";
        } else if (x1 == x2) {
            cout << (p1 < p2 ? "<" : ">");
        } else if (p1 == p2) {
            cout << (x1 < x2 ? "<" : ">");
        } else {
            if (to_string(x1).size() + p1 == to_string(x2).size() + p2) {
                cout << (to_string(x1) < to_string(x2) ? "<" : ">");
            } else {
                cout << (to_string(x1).size() + p1 < to_string(x2).size() + p2 ? "<" : ">"); 
            }
        }
        cout << "\n";
    }
}
