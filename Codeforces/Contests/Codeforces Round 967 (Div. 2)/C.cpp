/**
 *    author:  MaGnsi0
 *    created: 20.08.2024 18:20:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    function<int(int, int)> ask = [&](int u, int v) {
        cout << "? " << u + 1 << " " << v + 1 << endl;
        int x; cin >> x; x--; return x;
    };
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        set<int> to_visit;
        vector<bool> visited(n, false);
        vector<int> U, V;
        function<void(int, int)> get_path = [&](int u, int v) {
            if (u == v) { return; }
            if (visited[u] && visited[v]) { return; }
            int x = ask(u, v);
            to_visit.insert(u);
            to_visit.insert(x);
            to_visit.insert(v);
            if (x == u || x == v) {
                U.push_back(u + 1);
                V.push_back(v + 1);
                return;
            }
            get_path(u, x);
            get_path(v, x);
        };
        get_path(0, n - 1);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) { continue; }
            get_path(0, i);
            for (int v : to_visit) { visited[v] = true; }
            to_visit.clear();
        }
        cout << "!";
        for (int i = 0; i < n - 1; ++i) {
            cout << " " << U[i] << " " << V[i];
        }
        cout << endl;
    }
}
