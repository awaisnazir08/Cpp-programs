#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph
{
private:
    int numVertices;
    vector<vector<bool>> adjMatrix;
    vector<bool> visited;

public:
    Graph(int numVertices) : numVertices(numVertices), adjMatrix(numVertices, vector<bool>(numVertices, false)), visited(numVertices, false) {}

    void addEdge(int u, int v)
    {
        adjMatrix[u - 1][v - 1] = true;
        adjMatrix[v - 1][u - 1] = true; // Symmetry for undirected graphs
    }

    bool isAdjacent(int u, int v)
    {
        return adjMatrix[u - 1][v - 1];
    }

    void BFS(int startVertex)
    {
        queue<int> q;
        q.push(startVertex - 1);
        visited[startVertex - 1] = true;

        while (!q.empty())
        {
            int currentVertex = q.front();
            q.pop();
            cout << "Visiting vertex: " << currentVertex + 1 << endl;

            for (int i = 0; i < numVertices; ++i)
            {
                if (adjMatrix[currentVertex][i] && !visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
};

int main()
{
    Graph graph(8);
    graph.addEdge(1, 5);
    graph.addEdge(1, 2);
    graph.addEdge(2, 6);
    graph.addEdge(6, 3);
    graph.addEdge(6, 7);
    graph.addEdge(3, 7);
    graph.addEdge(3, 4);
    graph.addEdge(7, 4);
    graph.addEdge(4, 8);
    graph.addEdge(7, 8);

    if (graph.isAdjacent(1, 2))
    {
        cout << "Vertices 1 and 2 are connected!" << endl;
    }

    cout << "Starting BFS from vertex 2:" << endl;
    graph.BFS(2);

    return 0;
}
