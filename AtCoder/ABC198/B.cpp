//https://atcoder.jp/contests/abc198/tasks/abc198_b
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string s;
    cin >> s;
    int j;
    for (j = s.size () - 1; j >= 0; --j) {
        if (s[j] != '0')
            break;
    }
    for (int i = 0; i < (j + 1) / 2; ++i) {
        if (s[i] != s[j - i]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}

