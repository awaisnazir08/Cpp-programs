#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// time complexity = O(N) + O(2E) where 2E is the number of neigbors for each node(twice the edges)?
// class that creates a graph as well as also implements the breadth first search on the graph
class Graph
{
    // integer to record the number of nodes in the graph
    int num_of_vertices;

    // vector 2D array to record the edges of the nodes
    vector<vector<bool>> adjacencyMatrix;

    // vector array to mark the visited nodes to make sure they are not visited again
    vector<bool> visitedNodes;

public:
    // constructor to initialize the graph as per the number of nodes entered by the user
    Graph(int n)
    {
        if (n > 0)
        {
            num_of_vertices = n + 1;

            // initialized the vector 2D array to false, this means no edge between any nodes exist when the graph is initialized
            adjacencyMatrix = vector<vector<bool>>(num_of_vertices, vector<bool>(num_of_vertices, false));

            // initializing the visited nodes to false
            visitedNodes = vector<bool>(num_of_vertices, false);
        }
    }
    // function to add an undirected edge between two nodes
    /* for weighted graph, we will also be provided the weight, so instead of storing true
    we will store the weight in the below function
    this can be done for both directed and undirected graphs..!!
    */
    void addDirectedEdge(int n1, int n2)
    {
        adjacencyMatrix[n1][n2] = true;
    }

    // Breadth-First Search traversal starting from a given node
    /**
     * The function performs a breadth-first search traversal on a graph starting from a given node.
     *
     * @param node The parameter "node" represents the starting node from which the breadth-first
     * search will begin.
     */

    bool detectCycle(int node, vector<int> &visited)
    {
        visited[node] = 1;
        for (int i = 0; i < num_of_vertices; i++)
        {
            if (adjacencyMatrix[node][i])
            {
                if (visited[i] == 0)
                {
                    if (detectCycle(i, visited))
                    {
                        return true;
                    }
                }
                else if (visited[i] == 1)
                {
                    return true;
                }
            }
        }
        visited[node] = 2;
        return false;
    }

    bool isCyclic()
    {
        // Mark all the vertices as not visited
        for (auto i = 0; i < num_of_vertices; i++)
        {
            vector<int> visited(num_of_vertices, 0);
            if (detectCycle(i, visited))
            {
                return true;
            }
        }
        return false;
    }
};

// Main function to test the Graph class
int main()
{

    // Create a graph with 8 vertices as per the lab requirement
    Graph graph(8);

    // Add edges to create the graph as provided in the lab document
    graph.addDirectedEdge(1, 5);
    graph.addDirectedEdge(1, 2);
    graph.addDirectedEdge(2, 6);
    graph.addDirectedEdge(6, 3);
    graph.addDirectedEdge(6, 7);
    graph.addDirectedEdge(3, 7);
    graph.addDirectedEdge(3, 4);
    graph.addDirectedEdge(7, 4);
    graph.addDirectedEdge(4, 8);
    graph.addDirectedEdge(8, 7);

    if (graph.isCyclic())
    {
        cout << "Yes"<< endl;
    }
    else
    {
        cout << "No" << endl;
    }

    Graph graph2(5);
    graph2.addDirectedEdge(1, 2);
    graph2.addDirectedEdge(2, 3);
    graph2.addDirectedEdge(2, 4);
    graph2.addDirectedEdge(3, 5);
    graph2.addDirectedEdge(1, 5);
    if (graph2.isCyclic())
    {
        cout << "Yes";
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
