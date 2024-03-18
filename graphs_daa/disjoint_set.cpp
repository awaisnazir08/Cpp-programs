#include<bits/stdc++.h>
#include<vector>
using namespace std;
class DisjointSet
{
    vector<int> rank, parent;
    Public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for(int i = 0; i <=n; i++)
        {
            parent[i] = i;
        }

    }

    int findUltimateParent(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if(ulp_u == ulp_v)
        {
            return;
        }
        if(rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else 
        {
            //can do the other way round as well
            parent[ulp_u] = ulp_v;
            rank[ulp_V]++;
        }
    }
};
int main()
{
    // cout<<"Hello";
    return 0;
}