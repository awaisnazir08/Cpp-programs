#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int WHITE = 0;
const int GREY = 1;
const int BLACK = 2;
const int INF = 765664;

void BFS(vector<vector<int>>& adjList, int s) {
    int n = adjList.size();
    vector<int> color(n, WHITE);
    vector<int> d(n, INF);
    vector<int> pi(n, -1);

    color[s] = GREY;
    d[s] = 0;
    pi[s] = -1;

    queue<int> Q;
    Q.push(s);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int v : adjList[u]) {
            if (color[v] == WHITE) {
                color[v] = GREY;
                d[v] = d[u] + 1;
                pi[v] = u;
                Q.push(v);
            }
        }

        color[u] = BLACK;
    }
}

int main() {
    int numVertices = 6;
    vector<vector<int>> adjList(numVertices);

    // Example graph representation (Adjacency List)
    adjList[0] = {1, 2};
    adjList[1] = {0, 3, 4};
    adjList[2] = {0, 4};
    adjList[3] = {1, 5};
    adjList[4] = {1, 2, 5};
    adjList[5] = {3, 4};

    // Starting vertex for BFS
    int startVertex = 0;
    
    BFS(adjList, startVertex);

    return 0;
}
