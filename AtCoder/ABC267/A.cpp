/**
 *    author:  MaGnsi0
 *    created: 03.09.2022 13:58:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    if (s == "Monday") {
        cout << 5;
    } else if (s == "Tuesday") {
        cout << 4;
    } else if (s == "Wednesday") {
        cout << 3;
    } else if (s == "Thursday") {
        cout << 2;
    } else {
        cout << 1;
    }
}
