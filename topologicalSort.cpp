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

    return 0;
}