#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(202);
bool visited[202];
int n, m;

void dfs(vector<int> &plan, int n){
    visited[n] = 1;
    for(auto path : v[n])
        if(!visited[path])
            dfs(plan, path);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    // 연결 정보
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
        {
            int a;
            cin >> a;

            // 1일 때 연결
            if(a) { v[i].push_back(j); }
        }


    // 여행 계획
    vector<int> plan(m, 0);
	for(int i=0; i<m; i++)
		cin >> plan[i];

    dfs(plan, plan[0]);

    // 모두 방문했을 때 YES
    for(int i=0; i<m; i++) {
        if(!visited[plan[i]])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    
    return 0;
}