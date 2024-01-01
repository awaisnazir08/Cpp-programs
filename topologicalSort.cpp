#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//topological sort exists only on directed acyclic graphs (DAG)
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

    vector<int> TopologicalSort()
    {
        queue<int> q;
        vector<int> inDeg = inDegrees;
        vector<int> result;
        for(int i = 0; i < num_of_vertices; i++)
        {
            if(inDeg[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int out = q.front();
            result.push_back(out);
            q.pop();
            for(int i = 0; i < num_of_vertices; i++)
            {
                if(adjacencyMatrix[out][i])
                {
                    inDeg[i]--;
                    if(inDeg[i] == 0)
                    {
                        q.push(i);
                    }
                }
            }
        }
        return result;

    }
};
int main()
{
    Graph g(7);
    g.addDirectedEdge(1, 2);
    g.addDirectedEdge(1, 4);
    g.addDirectedEdge(2, 3);
    g.addDirectedEdge(2, 4);
    g.addDirectedEdge(2, 5);
    g.addDirectedEdge(3, 4);
    g.addDirectedEdge(5, 3);
    g.addDirectedEdge(6, 3);
    g.addDirectedEdge(6, 5);
    g.calculateDegrees();
    cout << "Topological Sort:" << endl;
    vector<int> result = g.TopologicalSort();
    for (int vertex : result) {
        cout << vertex << " ";
    }
    cout << endl;
    return 0;
}