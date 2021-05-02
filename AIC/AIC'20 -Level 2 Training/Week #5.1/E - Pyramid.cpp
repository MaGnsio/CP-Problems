//https://vjudge.net/contest/434102#problem/E
#include <bits/stdc++.h>
using namespace std;

void print (int n, string s) {
    if (n < 1) {
        return;
    }
    print (n - 1, s);
    cout << s;
}

void solve (int n, int s) {
    if (n < 1) {
        return;
    }
    solve (n - 2, s + 1);
    print (s, " ");
    print (n, "*");
    print (1, "\n");
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    solve (2 * n - 1, 0);
}

