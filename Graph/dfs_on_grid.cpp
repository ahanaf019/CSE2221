#include<bits/stdc++.h>

using namespace std;


int visited[10000][10000];
vector<pair<int, int>> moves = {{1,0},{-1,0},{0,-1},{0,1}};

bool valid(int x, int y, int m, int n)
{
    if(x < 0 || x >= m || y >= n || y < 0)
        return false;

    if(visited[x][y])
        return false;
    
    return true;
}

void dfs(int x, int y, int m, int n)
{
    visited[x][y] = true;

    for(auto move : moves)
    {
        if (valid(x + move.first, y + move.second, m, n))
        {
           dfs(x + move.first, y + move.second, m, n);
        }
        
    }


}

int main()
{
    int m, n;
    cin>>m>>n;
    string c;
    int res = 0;

    for(int i = 0; i < m; i++)
    {
        cin>>c;
        // cout<<c<<endl;
        for(int j = 0; j < n; j++)
        {
            if (c[j] == '.')
            {
                visited[i][j] = false;
            }
            else
            {
                visited[i][j] = true;
            }
            // cout<<j;
        }
    }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!visited[i][j])
                {
                    dfs(i, j, m, n);
                    res += 1;
                }
            }
        }
    cout<<res<<endl;

    return 0;
}
