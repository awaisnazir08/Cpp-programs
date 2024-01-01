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
    void addEdge(int n1, int n2)
    {
        adjacencyMatrix[n1][n2] = true;
        adjacencyMatrix[n2][n1] = true;
    }

    // Breadth-First Search traversal starting from a given node
    /**
     * The function performs a breadth-first search traversal on a graph starting from a given node.
     *
     * @param node The parameter "node" represents the starting node from which the breadth-first
     * search will begin.
     */
    void breadth_first_search(int node)
    {
        // Queue to store nodes to be processed in BFS
        queue<int> q;
        q.push(node);

        // Continue breadth first search until the queue is empty
        while (!q.empty())
        {
            // Get the front(first) node in the queue
            int currentNode = q.front();
            q.pop();

            // Check if the node has not been visited yet, then visit it, else skip it
            if (!visitedNodes[currentNode])
            {
                // Mark the current node as visited
                visitedNodes[currentNode] = true;

                // Print a message indicating the visit
                cout << "Visiting node: " << currentNode << endl;

                // Enqueue unvisited neighbors of the current node
                for (int i = 0; i < num_of_vertices; i++)
                {
                    if (adjacencyMatrix[currentNode][i] && !visitedNodes[i])
                    {
                        q.push(i);
                    }
                }
            }
        }
    }
    // dfs traversal time complexity
    // time complexitY for undirected graph: O(N) + O(2E)  (summation of degrees)
    // time complexity for directed graph: O(N) + O(E)
    void dfshelper(int node, vector<bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";
        for (int i = 0; i < num_of_vertices; i++)
        {
            if (adjacencyMatrix[node][i] && !visited[i])
            {
                dfshelper(i, visited);
            }
        }
    }

    void depthFirstTraversal(int node)
    {
        vector<bool> visited(num_of_vertices, false);
        // visited[node] = true;
        dfshelper(node, visited);
    }

    bool detectCycle(int node, int parent, vector<bool> &visited)
    {
        visited[node] = true;
        for (int i = 0; i < num_of_vertices; i++)
        {
            if (adjacencyMatrix[node][i] && !visited[i])
            {
                if (detectCycle(i, node, visited))
                {
                    return true;
                }
            }
            else if (adjacencyMatrix[node][i] && visited[i] && i != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool isCyclic()
    {
        // Mark all the vertices as not visited
        for (auto i = 0; i < num_of_vertices; i++)
        {
            vector<bool> visited(num_of_vertices, false);
            if (detectCycle(i, -1, visited))
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

    // Start BFS from vertex 2
    cout << "Starting Breadth First Search from node 2:" << endl;
    graph.breadth_first_search(2);
    graph.depthFirstTraversal(7);

    Graph graph2(5);
    graph2.addEdge(1, 2);
    graph2.addEdge(2, 3);
    graph2.addEdge(2, 4);
    graph2.addEdge(3, 5);
    graph2.addEdge(1,5);
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
