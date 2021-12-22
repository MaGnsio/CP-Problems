/**
 *    author:  MaGnsi0
 *    created: 22.12.2021 02:11:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input1.txt", "r", stdin);
    int64_t horizontal = 0, depth = 0, amount;
    string command;
    while (cin >> command >> amount) {
        if (command == "up") {
            depth -= amount;
        } else if (command == "down") {
            depth += amount;
        } else {
            horizontal += amount;
        }
    }
    cout << horizontal * depth;
}
