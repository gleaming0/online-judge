#include <bits/stdc++.h>
using namespace std;
bool land[52][52];
bool visited[52][52];

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int y, int x)
{
    if(land[y][x] == true && visited[y][x] == false)
    {
        visited[y][x] = 1;
    
        for(int i=0; i<8; i++)
            for(int j=0; j<8; j++)
                dfs(y+dy[i], x+dx[j]);
    }
    
}

int main()
{
   int w, h;
   w=1; h=1;
   while(cin >> w >> h)
   {
        if(w==0 && h==0)
            break;

        // 초기화
        for(int i=0; i<h+2; i++)
        {
            for(int j=0; j<w+2; j++)
            {
                land[0][j] = 0;
                land[i][0] = 0;
                land[h+1][j] = 0;
                land[i][w+1] = 0;
                visited[i][j] = 0;
            }
        }

        // 입력받기
        for(int i=1; i<=h; i++)
        {
            for(int j=1; j<=w; j++)
                cin >> land[i][j];
        }

        int cnt = 0;

        for(int i=1; i<=h; i++)
        {
            for(int j=1; j<=w; j++)
            {
                if(land[i][j] == true && visited[i][j] == false)
                {
                    cnt++;
                    dfs(i, j);
                }
            }
        }

        cout << cnt << "\n";
   }

    return 0;
}