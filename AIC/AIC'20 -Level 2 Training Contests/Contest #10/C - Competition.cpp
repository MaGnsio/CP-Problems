//https://vjudge.net/contest/436257#problem/C
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int X, Y, Z;
    cin >> X >> Y >> Z;
    int H = (Y * Z + X - 1) / X - 1;
    cout << max(H, 0);
}

