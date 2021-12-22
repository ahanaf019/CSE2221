#include<bits/stdc++.h>

using namespace std;

class Graph {
    public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int v)
    {
        visited[v] = true;
        cout<<v<<"->";
        for(auto i : adj[v])
        {
            if(!visited[i])
                DFS(i);
        }
    }
};



int main()
{
    Graph g;
    g.add_edge(1, 5);
    g.add_edge(5, 2);
    g.add_edge(5, 6);
    g.add_edge(6, 8);
    g.add_edge(6, 4);
    g.add_edge(2, 8);
    g.add_edge(3, 7);

    g.DFS(5);
    cout<<endl;
    g.DFS(7);

    return 0;
}