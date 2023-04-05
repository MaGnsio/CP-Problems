/**
 *    author:  MaGnsi0
 *    created: 11.02.2023 17:26:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string n;
        cin >> n;
        string x, y;
        for (auto& c : n) {
            if ((c - '0') & 1) {
                x += (c - '0') / 2 + '0';
                y += (c - '0' + 1) / 2 + '0';
                swap(x, y);
            } else {
                x += (c - '0') / 2 + '0';
                y += (c - '0') / 2 + '0';
            }
        }
        cout << stoi(x) << " " << stoi(y) << "\n";
    }
}
