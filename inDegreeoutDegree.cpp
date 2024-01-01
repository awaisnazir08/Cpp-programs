#include<iostream>
#include<vector>
using namespace std;
class Graph
{
    int num_of_vertices;
    vector<vector<bool>> adjacencyMatrix;
    vector<int>inDegrees, outDegrees;
    public:
    Graph(int v): num_of_vertices(v), adjacencyMatrix(v, vector<bool>(v, false)), inDegrees(v, 0), outDegrees(v, 0)
    {

    }
    
    void addDirectedEdge(int from, int to)
    {
        adjacencyMatrix[from][to] = 1;
    }

    void printAdjacencyMatrix() const {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < num_of_vertices; ++i) {
            for (int j = 0; j < num_of_vertices; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void calculateDegrees()
    {
        for(int i = 0; i < num_of_vertices; i++)
        {
            for(int j = 0; j < num_of_vertices; j++)
            {
                if(adjacencyMatrix[i][j])
                {
                    outDegrees[i]++;
                    inDegrees[j]++;
                }
            }
        }
    }

    void printDegrees()
    {
        // Print the results
        cout << "Vertex\tIn-Degree\tOut-Degree" << endl;
        for (int i = 0; i < num_of_vertices; ++i) {
            cout << i << "\t" << inDegrees[i] << "\t\t" << outDegrees[i] << endl;
        }
    }

    void printAdjacencyList()
    {
        for(int i = 0; i < num_of_vertices; i++)
        {
            cout<<"Vertex "<<i<<" -> ";
            for(int j = 0; j < num_of_vertices; j++)
            {
                if(adjacencyMatrix[i][j])
                {
                    cout<<j<<" ";
                }
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph myGraph(5);

    // Add directed edges
    myGraph.addDirectedEdge(0, 1);
    myGraph.addDirectedEdge(0, 3);
    myGraph.addDirectedEdge(1, 0);
    myGraph.addDirectedEdge(1, 2);
    myGraph.addDirectedEdge(2, 3);
    myGraph.addDirectedEdge(3, 1);
    myGraph.addDirectedEdge(1, 4);

    // Print the adjacency matrix
    myGraph.printAdjacencyMatrix();

    // Calculate and print in-degree and out-degree
    myGraph.calculateDegrees();
    myGraph.printDegrees();
    myGraph.printAdjacencyList();
    return 0;
}