//https://vjudge.net/contest/433801#problem/J
#include <bits/stdc++.h>
using namespace std;

vector<int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, cnt = 0;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    for (int i = 0; i < 37 - n; ++i) {
        bool chk = true;
        for (int j = 0; j < n; ++j) {
            if ((v[j] == month[i + j]) || (v[j] == 29 && month[i + j] == 28 && cnt == 0)) {
                if (v[j] == 29) {
                    cnt++;
                }
                continue;
            }
            chk = false;
            break;
        }
        if (chk) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}

