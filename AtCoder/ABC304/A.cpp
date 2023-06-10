/**
 *    author:  MaGnsi0
 *    created: 03.06.2023 15:00:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> age(n);
    vector<string> name(n);
    for (int i = 0; i < n; ++i) {
        cin >> name[i] >> age[i];
    }
    int youngest = *min_element(age.begin(), age.end());
    for (int i = 0; i < n; ++i) {
        if (age[i] == youngest) {
            for (int j = i, k = 0; k < n; ++k) {
                cout << name[j] << "\n";
                j = (j + 1) % n;
            }
            return 0;
        }
    }
}
