//https://vjudge.net/contest/436257#problem/I
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int A, B;
    cin >> A >> B;
    for (int i = B; ; --i) {
        if ((B / i) - ((A - 1) / i) >= 2) {
            cout << i << " ";
            return 0;
        }
    }
}

