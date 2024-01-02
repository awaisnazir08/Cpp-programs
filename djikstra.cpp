#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Graph
{
private:
    int vertices;
    vector<vector<int>> adjacencyMatrix;

public:
    Graph(int v) : vertices(v), adjacencyMatrix(v, vector<int>(v, 0)) {}

    void addEdge(int from, int to, int weight)
    {
        adjacencyMatrix[from][to] = weight;
        // adjacencyMatrix[to][from] = weight; // Assuming an undirected graph
    }

    vector<int> dijkstra(int startVertex)
    {
        vector<int> distance(vertices, numeric_limits<int>::max());
        distance[startVertex] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, startVertex});

        while (!pq.empty())
        {
            int u = pq.top().second;
            // int dis = pq.top().first;
            pq.pop();

            for (int v = 0; v < vertices; ++v)
            {
                if (adjacencyMatrix[u][v] != 0)
                {
                    int newDistance = distance[u] + adjacencyMatrix[u][v];
                    if (newDistance < distance[v])
                    {
                        distance[v] = newDistance;
                        pq.push({distance[v], v});
                    }
                }
            }
        }

        return distance;
    }
};

int main()
{
    // Example usage:
    int vertices = 10;
    Graph graph(vertices);

    // Adding edges with weights
    graph.addEdge(1, 2, 4);
    graph.addEdge(1, 4, 1);
    graph.addEdge(1, 5, 8);
    graph.addEdge(2, 4, 2);
    graph.addEdge(2, 5, 6);
    graph.addEdge(2, 3, 1);
    graph.addEdge(2, 6, 1);
    graph.addEdge(3, 5, 2);
    graph.addEdge(3, 6, 5);
    graph.addEdge(4, 5, 11);
    graph.addEdge(4, 7, 9);
    graph.addEdge(4, 8, 8);
    graph.addEdge(5, 4, 2);
    graph.addEdge(5, 6, 3);
    graph.addEdge(5, 7, 1);
    graph.addEdge(5, 8, 1);
    graph.addEdge(5, 9, 8);
    graph.addEdge(6, 8, 7);
    graph.addEdge(6, 9, 8);
    graph.addEdge(7, 8, 2);
    graph.addEdge(7, 5, 4);
    graph.addEdge(8, 9, 3);



    int startVertex = 1;
    vector<int> distances = graph.dijkstra(startVertex);

    cout << "Shortest distances from vertex " << startVertex << ":\n";
    for (int i = 0; i < vertices; ++i)
    {
        cout << "To vertex " << i << ": " << distances[i] << "\n";
    }

    return 0;
}
