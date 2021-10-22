#include <bits/stdc++.h>
using namespace std;

int maxN = 1e5 + 5, maxM = maxN * (maxN - 1); //those numbers are hypothetical and may not apply on the real algorithm

struct edge {
    int u, v, w;
};

vector<vector<pair<int, int>>> adj(maxN);
vector<int> dist(maxN, INT_MAX), parent(maxN, -1), negative_path, path;
vector<bool> visited(maxN, false);
vector<edge> edges(maxM);

//dijkstra algorithm
/*
 *  works for graph with nonnegative cycles
 *  O(n * n + m)
 *  this complexity is optimal for dense graph as m ≈ n * n
 */
void dijkstra1(int source) {
    dist[source] = 0;
    for (int i = 0; i < maxN; ++i) {
        int v = -1;
        for (int j = 0; j < maxN; ++j) { //search for an unvisited vertex with the least ditance to the source
            if (!visited[j] && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }
        if (v == -1 || dist[v] == INT_MAX) { //all vertices that are reachable from the source already visited
            break;
        }
        visited[v] = true;
        for (auto& [u, w] : adj[v]) {
            if (dist[v] + w < dist[u]) { //relaxation
                dist[u] = dist[v] + w;
                parent[u] = v; //for retrieving path
            }
        }
    }
}

//dijkstra algorithm on sparse graph
/*
 *  in sparse graphs, when m is much smaller than the maximal number of edges (n*n), the complexity gets less optimal because of the first term.
 *  thus it is necessary to improve the execution time of the first operation (and of course without greatly affecting the second operation by much).
 *  to accomplish that we can use a variation of multiple auxiliary data structures.
 *  the most efficient is the fibonacci heap, which allows the first operation to run in O(logn), and the second operation in O(1).
 *  therefore we will get the complexity O(nlogn+m)
 *  however fibonnacci heaps are quite complex to implement, and also have a quite large hidden constant.
 *  as a compromise you can use data structures, that perform both types of operations (extracting a minimum and updating an item) in O(logn).
 *  then the complexity of Dijkstra's algorithm is O(nlogn+mlogn)=O(mlogn).
 *  C++ provides two such data structures: set and priority_queue.
 *  in practice the priority_queue version is a little bit faster than the version with set.
 */
//set version
void dijkstra2(int source) {
    set<pair<int, int>> s; //<dist, vertex>
    dist[source] = 0;
    s.insert({0, source});
    while (!s.empty()) {
        int v = s.begin()->second;
        s.erase(s.begin());
        for (auto& [u, w] : adj[v]) {
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                s.insert({dist[u], u});
                parent[u] = v; //for retrieving path
            }
        }
    }
}
//priority_queue version
void dijkstra3(int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dist[source] = 0;
    q.push({0, source});
    while (!q.empty()) {
        int v = q.top().second, dist_v = q.top().first;
        q.pop();
        if (dist_v != dist[v]) { //skip old versions that has already been handled
            continue;
        }
        for (auto& [u, w] : adj[v]) {
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                q.push({dist[u], u});
                parent[u] = v; //for retrieving path
            }
        }
    }
}

//0-1 bfs
/*
 *  we can extend this even further if we allow the weights of the edges to be even bigger.
 *  if every edge in the graph has a weight ≤ k, then the distances of vertices in the queue will differ by at most k from the distance of v to the source.
 *  so we can keep k+1 buckets for the vertices in the queue, and whenever the bucket corresponding to the smallest distance gets empty,
 *  we make a cyclic shift to get the bucket with the next higher distance. This extension is called Dial's algorithm.
 */
void bfs01(int source) {
    deque<int> q;
    dist[source] = 0;
    q.push_front(source);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto& [u, w] : adj[v]) {
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                parent[u] = v; //for retrieving path
                if (w == 1) {
                    q.push_back(u);
                } else {
                    q.push_front(u);
                }
            }
        }
    }
}

//bellman-ford
/*
 *  O(MN)
 *  any shortest path cannot have more than n−1 edges.
 *  therefore, the algorithm sufficiently goes up to the (n−1)th phase.
 *  after that, it is guaranteed that no relaxation will improve the distance to some vertex.
 */
//implementation 1
void bellman_ford1(int source) {
    dist[source] = 0;
    for (int i = 0; i < maxN - 1; ++i) {
        for (auto& [u, v, w] : edges) {
            if (dist[u] < INT_MAX) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u; //for retrieving path
                }
            }
        }
    }
}
//implementation 2
/*
 *  often we already get the answer in a few phases and no useful work is done in remaining phases, just a waste visiting all edges.
 *  so, let's keep the flag, to tell whether something changed in the current phase or not, and if any phase, nothing changed, the algorithm can be stopped.
 */
void bellman_ford2(int source) {
    dist[source] = 0;
    for (;;) {
        bool any = false;
        for (auto& [u, v, w] : edges) {
            if (dist[u] < INT_MAX) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u; //for retrieving path
                    any = true;
                }
            }
        }
        if (!any) {
            break;
        }
    }
}
//criterion for presence of a cycle of negative weights reachable for source vertexv
/*
 *  after (n−1)th phase, if we run algorithm for one more phase, and it performs at least one more relaxation,
 *  then the graph contains a negative weight cycle that is reachable from v; otherwise, such a cycle does not exist.
 */
void negative_cycle_detection_bellman_ford(int source) {
    int x;
    dist[source] = 0;
    for (int i = 0; i < maxN; ++i) { //run for N times
        x = -1;
        for (auto& [u, v, w] : edges) {
            if (dist[u] < INT_MAX) {
                if (dist[u] + w < dist[v]) {
                    /*
                     *  due to the presence of a negative cycle, for n iterations of the algorithm, the distances may go far in the negative range.
                     *  hence in the code, we adopted additional measures against the integer overflow as follows:
                     */
                    dist[v] = max(-100000, dist[u] + w);
                    parent[v] = u;
                    x = v;
                }
            }
        }
    }
    if (x == -1) { //if no relaxation happened in the nth phase
        //there is no negative cycle that is reachable from the source vertex
    } else {
        /*
         *  if such a cycle is found, the Bellman-Ford algorithm can be modified so that it retrieves this cycle as a sequence of vertices contained in it.
         *  for this, it is sufficient to remember the last vertex x for which there was a relaxation in nth phase.
         *  this vertex will either lie in a negative weight cycle, or is reachable from it.
         *  to get the vertices that are guaranteed to lie in a negative cycle, starting from the vertex x, pass through to the predecessors n times.
         *  hence we will get the vertex y, namely the vertex in the cycle earliest reachable from source.
         *  we have to go from this vertex, through the predecessors, until we get back to the same vertex y
         *  (and it will happen, because relaxation in a negative weight cycle occur in a circular manner).
         */
        int y = x;
        for (int i = 0; i < maxN; ++i) {
            y = parent[y];
        }
        for (int v = y; !(v == y && negative_path.size() > 1); v = parent[v]) {
            negative_path.push_back(v);
        }
        reverse(negative_path.begin(), negative_path.end());
    }
    /*
     *  the above implementation looks for a negative cycle reachable from some starting vertex v;
     *  however, the algorithm can be modified to just looking for any negative cycle in the graph.
     *  for this we need to put all the distance dist[i] to zero and not infinity — as if we are looking for the shortest path from all vertices simultaneously;
     *  the validity of the detection of a negative cycle is not affected.
     */
}

//shortest path faster algorithm (SPFA)
/*
 *  SPFA is a improvement of the Bellman-Ford algorithm which takes advantage of the fact that not all attempts at relaxation will work.
 *  the worst case of this algorithm is equal to the O(nm) of the Bellman-Ford,
 *  but in practice it works much faster and some people claim that it works even in O(m) on average.
 *  however be careful, because this algorithm is deterministic and it is easy to create counterexamples that make the algorithm run in O(nm).
 *  there are some care to be taken in the implementation, such as the fact that the algorithm continues forever if there is a negative cycle.
 *  to avoid this, it is possible to create a counter that stores how many times a vertex has been relaxed and stop the algorithm as soon as some vertex got
 *  relaxed for the n-th time. Note, also there is no reason to put a vertex in the queue if it is already in.
 */
bool spfa(int source) {
    vector<int> relaxation_counter(maxN, 0);
    vector<bool> in_queue(maxN, false);
    queue<int> q;
    dist[source] = 0;
    q.push(source);
    in_queue[source] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        in_queue[v] = false;
        for (auto& [u, w] : adj[v]) {
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                if (!in_queue[u]) {
                    q.push(u);
                    in_queue[u] = true;
                    relaxation_counter[u]++;
                    if (relaxation_counter[u] > maxN) {
                        return false; //negative cycle
                    }
                }
            }
        }
    }
    return true;
}

//floyd-warshall
/*
 *  O(v^3)
 *  the key idea of the algorithm is to partition the process of finding the shortest path between any two vertices to several incremental phases.
 */
vector<vector<int>> floyd_warshall() {
    vector<vector<int>> d(maxN, vector<int>(maxN, INT_MAX));
    for (int i = 0; i < maxN; ++i) {
        d[i][i] = 0;
    }
    for (auto& [u, v, w] : edges) {
        d[u][v] = w;
    }
    for (int k = 0; k < maxN; ++k) {
        for (int i = 0; i < maxN; ++i) {
            for (int j = 0; j < maxN; ++j) {
                if (d[i][k] < INT_MAX && d[k][j] < INT_MAX) {
                    d[i][j] = max(min(d[i][j], d[i][k] + d[k][j]), -1000000); //avoiding overflow
                }
            }
        }
    }
    return d;
}
//floyd_warshall path retrieving
void floyd_warshall_path(int u, int v) {
    vector<vector<int>> d(maxN, vector<int>(maxN, INT_MAX));
    vector<vector<int>> p(maxN, vector<int>(maxN, -1));
    for (int i = 0; i < maxN; ++i) {
        d[i][i] = 0;
        p[i][i] = 0;
    }
    for (auto& [u, v, w] : edges) {
        d[u][v] = w;
        p[u][v] = v;
    }
    for (int k = 0; k < maxN; ++k) {
        for (int i = 0; i < maxN; ++i) {
            for (int j = 0; j < maxN; ++j) {
                if (d[i][k] < INT_MAX && d[k][j] < INT_MAX) {
                    if (d[i][j] > d[i][k] + d[k][j]) {
                        d[i][j] = max(d[i][k] + d[k][j], -1000000); //avoiding overflow
                        p[i][j] = p[i][k];
                    }
                }
            }
        }
    }
    if (p[u][v] == -1) {
        //no path exist
    } else {
        path.push_back(u);
        int x = u;
        while (x != v) {
            x = p[x][v];
            path.push_back(x);
        }
    }
}
//find negative cycle using floyd-warshall
void negative_cycle_detection_floyd_warshall() {
    vector<vector<int>> d = floyd_warshall();
    for (int i = 0; i < maxN; ++i) {
        for (int j = 0; j < maxN; ++j) {
            for (int t = 0; t < maxN; ++t) {
                if (d[i][t] < INT_MAX && d[t][t] < 0 && d[t][j] < INT_MAX) {
                    d[i][j] = INT_MIN;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
}
