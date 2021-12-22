#include<iostream>
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

    void dfs(int v)
    {
        visited[v] = true;
        // cout<<v<<"->";
        for(auto i: adj[v])
        {
            if(!visited[i])
            {
                dfs(i);
            }
        }
    }
};


int main()
{
    graph g;

    int m, n;
    vector<pair<int, int>> con;
    int res = 0;
    cin>>m>>n;

    for(int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        g.add_edge(x,y);
    }

    for(int i = 1; i <= m; i++)
    {
        // cout<<g.visited[i]<<"*"<<i<<" ";
        if(!g.visited[i])
        {
            g.dfs(i);
            con.push_back({1, i});
            res++;
        }
    }

    cout<<res-1<<endl;;
    for(int i = 1; i < res; i++)
    {
        cout<<con[i].first<<" "<<con[i].second<<endl;
    }

    return 0;
}