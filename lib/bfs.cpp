#include <bits/stdc++.h>
using namespace std;

int maxN = 1e5 + 5, maxM = maxN * (maxN - 1); //those numbers are hypothetical and may not apply on the real algorithm

vector<vector<int>> adj(maxN);
vector<bool> visited(maxN, false);
vector<int> parent(maxN, -1), distance(maxN, 0)/*distance between source_vertex and node v = distance[v]*/;
queue<int> q;

//normal bfs
void bfs(int source_vertex) {
    visited[source_vertex] = true;
    q.push(source_vertex);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
                parent[u] = v;
                distance[u] = distance[v] + 1;
            }
        }
    }
}

//find shortest path from u to v
/*
 *  the path found by bfs to any node is the shortest path to that node
 *  while dfs finds the lexicographical first path in the graph from a source vertex u to each vertex.
 *  dfs will also find the shortest paths in a tree (because there only exists one simple path).
 */
void find_shortest_path(int u, int v) {
    bfs(u);
    vector<int> path;
    for (int k = v; k != -1; k = parent[k]) {
        path.push_back(k);
    }
    reverse(path.begin(), path.end());
}


/*
 *  finding the shortest cycle in a directed unweighted graph: start a bfs from each vertex.
 *  as soon as we try to go from the current vertex back to the source vertex, we have found the shortest cycle containing the source vertex.
 *  at this point we can stop the bfs, and start a new bfs from the next vertex.
 *  from all such cycles (at most one from each bfs) choose the shortest.
 */

/*
 *  find all the edges that lie on any shortest path between a given pair of vertices (a,b).
 *  to do this, run two breadth first searches: one from a and one from b.
 *  let da[] be the array containing shortest distances obtained from the first bfs (from a) and
 *  db[] be the array containing shortest distances obtained from the second bfs from b.
 *  now for every edge (u,v) it is easy to check whether that edge lies on any shortest path between a and b: the criterion is the condition da[u]+1+db[v]=da[b].
 */

/*
 *  find all the vertices on any shortest path between a given pair of vertices (a,b).
 *  to accomplish that, run two breadth first searches: one from a and one from b.
 *  let da[] be the array containing shortest distances obtained from the first bfs (from a) and
 *  db[] be the array containing shortest distances obtained from the second bfs (from b).
 *  now for each vertex it is easy to check whether it lies on any shortest path between a and b: the criterion is the condition da[v]+db[v]=da[b].
 */

/*
 *  find the shortest path of even length from a source vertex s to a target vertex t in an unweighted graph:
 *  for this, we must construct an auxiliary graph, whose vertices are the state (v,c), where v - the current node, c=0 or c=1 - the current parity.
 *  any edge (a,b) of the original graph in this new column will turn into two edges ((u,0),(v,1)) and ((u,1),(v,0)).
 *  after that we run a bfs to find the shortest path from the starting vertex (s,0) to the end vertex (t,0).
 */

//edge split and vertex split for small constrained weights.

//shortest path from a group of vertices to another group? push a whole group to queue and run the bfs

//check if the graph is bipartite(bicolorable)

//find cycles

/*
 *  classification of edges
 *  While bfs on an undirected graph, we have the following properties:
 *   • there are no back and no forward edges.
 *   • for each tree edge (u, v) we have d[v] = d[u] + 1.
 *   • for each cross edge (u, v) we have d[v] = d[u] or d[v] = d[u] + 1.
 *  While bfs on a directed graph, we have the following properties:
 *   • there are no forward edges;
 *   • for each tree edge (u, v) we have d[v] = d[u] + 1.
 *   • for each cross-edge (u, v) we have d[v] ≤ d[u] + 1.
 *   • for each back edge (u, v) we have 0 ≤ d[v] ≤ d[u].
 */


int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
}
