#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Graph
{
    int num_of_vertices;
    vector<vector<int>>adjacencyList;
    public:
    Graph(int nodes) : adjacencyList(nodes + 1), num_of_vertices(nodes + 1) {}
    
    /**
     * The addEdge function adds an edge between two vertices in a graph by updating the adjacency
     * list.
     * 
     * @param from The "from" parameter represents the starting vertex of the edge.
     * @param to The "to" parameter represents the vertex to which an edge is being added.
     */
    // this is the undirected graph, directed graph can also be made by simply not making the second push below
    void addEdge(int from, int to)
    {
        adjacencyList[from].push_back(to);
        // adjacencyList[to].push_back(from);
    }

    void printAdjacencyList()
    {
        for(int i = 0; i < num_of_vertices; i++)
        {
            cout<<"Vertex: "<<i<<" -> ";
            for(auto it: adjacencyList[i])
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }


};
int main()
{
    Graph myGraph(4);

    // Add directed edges
    myGraph.addEdge(0, 1);
    myGraph.addEdge(0, 3);
    myGraph.addEdge(1, 0);
    myGraph.addEdge(1, 2);
    myGraph.addEdge(2, 3);
    myGraph.addEdge(3, 1);

    // Print the adjacency list
    myGraph.printAdjacencyList();


    return 0;
}