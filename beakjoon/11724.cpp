#include <bits/stdc++.h>
using namespace std;

void dfs(int curr, vector<vector<int>> &v, vector<bool> &visited)
{
    visited[curr] = true;

    for(int next : v[curr])
    {
        if(visited[next] == false)
            dfs(next, v, visited);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> v(n+1, vector<int>());
    vector<bool> visited(n+1, false);

    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    int cnt = 0;

    for(int i=1; i<=n; i++)
    {
        if(visited[i] == false)
        {
            cnt++;
            dfs(i, v, visited);
        }
    }

    cout << cnt;
    return 0;
}