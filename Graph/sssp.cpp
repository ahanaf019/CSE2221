// Single Source Shortest Path (on trees)

#include<bits/stdc++.h>

using namespace std;

class graph {
    public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    map<int, int> distance;

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int n, int dist)
    {
        visited[n] = true;
        distance[n] = dist;

        for(auto i : adj[n])
        {
            if(!visited[i])
            {
                dfs(i, dist + 1);
            }
        }
    }

    void print_dist(int n)
    {
        cout<<endl;
        for(int i = 1; i <= n; i++)
        {
            cout<<distance[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    graph g;
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(2,4);
    g.add_edge(4,5);
    g.add_edge(4,6);

    g.dfs(2, 0);
    g.print_dist(6);

    return 0;
}