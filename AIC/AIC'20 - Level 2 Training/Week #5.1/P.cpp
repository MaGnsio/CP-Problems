//https://vjudge.net/contest/434102#problem/P
#include <bits/stdc++.h>
using namespace std;

bool isFib (int n) {
    int x = (5 * n * n + 4);
    int y = (5 * n * n - 4);
    int a = sqrt (x), b = sqrt (y);
    return (a * a == x || b * b == y);
}

void name (int n, int idx, string& s) {
    if (idx == n) {
        return;
    }
    if (isFib (idx + 1)) {
        s.push_back ('O');
    } else {
        s.push_back ('o');
    }
    name (n, idx + 1, s);
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    string s = "";
    cin >> n;
    name (n, 0, s);
    cout << s;
}

