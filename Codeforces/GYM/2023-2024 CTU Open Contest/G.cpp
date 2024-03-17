/**
 *    author:  MaGnsi0
 *    created: 01.02.2024 17:26:09
**/
#include <bits/stdc++.h>

using namespace std;

const int dx1[4] = {-1, 0, 0, 1};
const int dy1[4] = {0, -1, 1, 0};
const int dx2[8] = {-2, -1, -1, 0, 0, 1, 1, 2};
const int dy2[8] = {0, -1, 1, 2, -2, -1, 1, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    set<pair<int, int>> points;
    set<tuple<int, int, int, int>> edges;
    map<pair<int, int>, set<pair<int, int>>> adj;
    for (int i = 0; i < n; ++i) {
        int x1, y1; cin >> x1 >> y1;
        int x2, y2; cin >> x2 >> y2;
        points.emplace(x1, y1);
        points.emplace(x2, y2);
        edges.emplace(x1, y1, x2, y2);
        edges.emplace(x2, y2, x1, y1);
        adj[{x1, y1}].emplace(x2, y2);
        adj[{x2, y2}].emplace(x1, y1);
    }
    //Test 0
    {
        set<pair<int, int>> done;
        function<void(int, int, int, int)> dfs = [&](int x, int y, int px, int py) {
            done.emplace(x, y);
            for (auto [nx, ny] : adj[{x, y}]) {
                if (nx == px && ny == py) { continue; }
                if (done.count({nx, ny})) {
                    cout << 0;
                    exit(0);
                }
                dfs(nx, ny, x, y);
            }
        };
        for (auto [x, y] : points) {
            if (done.count({x, y})) { continue; }
            dfs(x, y, INT_MAX, INT_MAX);
        }
    }
    //Test 1
    {
        int cur_comp = 0;
        map<pair<int, int>, int> comp;
        function<void(int, int)> dfs = [&](int x, int y) {
            comp[{x, y}] = cur_comp;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx1[i];
                int ny = y + dy1[i];
                if (comp.count({nx, ny}) == 0) { continue; }
                if (adj[{x, y}].count({nx, ny})) { continue; }
                if (comp[{nx, ny}] == cur_comp) {
                    cout << 1;
                    exit(0);
                }
            }
            for (auto [nx, ny] : adj[{x, y}]) {
                if (comp.count({nx, ny})) { continue; }
                dfs(nx, ny);
            }
        };
        for (auto [x, y] : points) {
            if (comp.count({x, y})) { continue; }
            dfs(x, y);
            cur_comp++;
        }
    }
    //Test 2
    {
        int cur_comp = 0;
        map<pair<int, int>, int> comp;
        function<void(int, int)> dfs = [&](int x, int y) {
            comp[{x, y}] = cur_comp;
            //same comp
            for (int i = 0; i < 8; ++i) {
                int nx = x + dx2[i];
                int ny = y + dy2[i];
                if (comp.count({nx, ny}) == 0) { continue; }
                if (dx2[i] == 0 || dy2[i] == 0) {
                    bool bad = false;
                    for (int j = 0; j < 4; ++j) {
                        int px = x + dx1[i];
                        int py = y + dy1[i];
                        if (edges.count({x, y, px, py}) && edges.count({px, py, nx, ny})) {
                            bad = true;
                            break;
                        }
                    }
                    if (bad) { continue; }
                }
                if (comp[{nx, ny}] == cur_comp) {
                    cout << 2;
                    exit(0);
                }
            }
            //diff comp
            for (auto [nx, ny] : adj[{x, y}]) {
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        int cx = x + dx1[i];
                        int cy = y + dy1[i];
                        int cnx = nx + dx1[i];
                        int cny = ny + dy1[i];
                        if (comp.count({cx, cy}) == 0) { continue; }
                        if (comp.count({cnx, cny}) == 0) { continue; }
                        if (comp[{cx, cy}] != comp[{cnx, cny}]) { continue; }
                        if (adj[{cx, cy}].count({cnx, cny}) == 0) { continue; }
                        if (comp[{cx, cy}] == cur_comp) { continue; }
                        cout << 2;
                        exit(0);
                    }
                }
            }
            for (auto [nx, ny] : adj[{x, y}]) {
                if (comp.count({nx, ny})) { continue; }
                dfs(nx, ny);
            }
        };
        for (auto [x, y] : points) {
            if (comp.count({x, y})) { continue; }
            dfs(x, y);
            cur_comp++;
        }
    }
    cout << 3;
}
