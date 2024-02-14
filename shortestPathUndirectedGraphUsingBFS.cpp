#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        vector<int> adj[N];
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> distance(N, 1e9);
        distance[src] = 0;

        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();

            for (int neighbor : adj[currentNode]) {
                int dis = distance[currentNode] + 1;
                if (dis < distance[neighbor]) {
                    q.push(neighbor);
                    distance[neighbor] = dis;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (distance[i] == 1e9) {
                distance[i] = -1;
            }
        }

        return distance;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {0, 4}};
    int N = 5;
    int M = edges.size();
    int src = 0;

    vector<int> result = sol.shortestPath(edges, N, M, src);

    cout << "Shortest distances from node " << src << " to all other nodes:\n";
    for (int dist : result) {
        cout << dist << " ";
    }

    return 0;
}
