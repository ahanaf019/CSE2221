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

    void dfs(int n)
    {
        visited[n] = true;

        for(auto i : adj[n])
        {
            if(!visited[i])
                dfs(i);
        }
    }

    void print(int n)
    {
        cout<<endl;

        for(int i = 1; i <= n; i++)
        {
            cout<<visited[i]<<" ";
        }
        cout<<endl;
    }

};


int main()
{
    int m,n;
    cin>>m>>n;

    graph g;
    int x,y;
    for(int i = 0; i < n; i++)
    {
        cin>>x>>y;
        g.add_edge(x,y);
    }
    int sec = 0;
    for(int i = 1; i <= m; i++)
    {
        if(!g.visited[i])
        {
            g.dfs(i);
            // g.print(m);
            sec++;
        }
    }
    cout<<sec<<endl;

    return 0;
}