/**
 *    author:  MaGnsi0
 *    created: 27.09.2023 17:56:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string x1, y1;
    cin >> x1 >> y1;
    string x2, y2;
    cin >> x2 >> y2;
    if (x1 == "AD" && x2 == "AD") {
        cout << abs(stoi(y1) - stoi(y2));
    } else if (y1 == "BC" && y2 == "BC") {
        cout << abs(stoi(x1) - stoi(x2));
    } else if (x1 == "AD") {
        cout << stoi(y1) + stoi(x2) - 1;
    } else {
        cout << stoi(x1) + stoi(y2) - 1;
    }
}
