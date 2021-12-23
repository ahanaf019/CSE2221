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
            {
                dfs(i);
            }
        }
    }

    bool check(int n)
    {
        for(int i = 1; i <=n; i++)
        {
            if(!visited[i]) return false;
        }

        return true;
    }

};


int main()
{
    int m, n;
    cin>>m>>n;
    graph g;

    int x,y;
    for(int i = 0; i < n; i++)
    {
        cin>>x>>y;
        g.add_edge(x,y);    
    }

    if(n != (m - 1))
    {
        cout<<"NO"<<endl;
        return 0;
    }

    else
    {
        g.dfs(1);

        if(g.check(m))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}