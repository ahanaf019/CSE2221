#include<bits/stdc++.h>

using namespace std;

class graph {
    public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void bfs(int v)
    {
        visited[v] = true;
        queue<int> q;
        q.push(v);

        while(!q.empty())
        {
            v = q.front();
            q.pop();
            cout<<v<<" ";

            for(auto i : adj[v])
            {
                if(!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }


        }


    }
};


int main()
{
    graph g;
    g.add_edge(1,2);
    g.add_edge(1,3);
    g.add_edge(1,4);
    g.add_edge(2,5);
    g.add_edge(2,6);
    g.add_edge(5,9);
    g.add_edge(5,10);
    g.add_edge(4,7);
    g.add_edge(4,8);
    g.add_edge(7,11);
    g.add_edge(7,12);
    g.add_edge(3,13);
    g.add_edge(13,14);

    g.bfs(1);

    return 0;
}