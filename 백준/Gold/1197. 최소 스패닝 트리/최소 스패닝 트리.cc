// 풀이2 - 프림 알고리즘
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct {
    int node, cost;
} nc;

int V, E;
vector<nc> *edge;

// overloading operator for priority queue
struct compare {
    bool operator()(const nc &a, const nc &b) {
        return a.cost > b.cost;
    }
};

// Prim's Algorithm
int mst() {
    priority_queue<nc, vector<nc>, compare> pq; // pq for minimum cost
    bool *visited = new bool[V+1]();

    for (nc &e : edge[1]) pq.push(e); // start from node 1
    visited[1] = 1;

    int weights = 0;
    
    for (int i = 0; i < V-1;) {
        nc minEdge = pq.top();
        pq.pop();

        if (visited[minEdge.node]) continue; // skip visited node
        visited[minEdge.node] = 1;
        i++; // increment visited node count

        weights += minEdge.cost;

        for (nc &e : edge[minEdge.node]) {
            if (!visited[e.node]) pq.push(e);
        }
    }

    delete[] visited;

    return weights;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> E;

    edge = new vector<nc>[V+1];
    for (int i = 0, A, B, C; i < E; i++) {
        cin >> A >> B >> C;
        
        edge[A].push_back({B, C});
        edge[B].push_back({A, C});
    }

    cout << mst();

    delete[] edge;
    return 0;
}