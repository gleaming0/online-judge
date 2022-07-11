#include <bits/stdc++.h>
using namespace std;

bool N_visited[101][101];
bool Y_visited[101][101];
int N_cnt[3]; //[0]: R, [1]: G, [2]: B
int Y_cnt[3]; //[0]: R+G, [2]: B

int dy[4] = {-1, 1, 0, 0}; //상 하 좌 우
int dx[4] = {0, 0, -1, 1};
int n;

void check(vector<vector<int>> &v, bool (&visited)[101][101], int y, int x, int color)
{
    if(!visited[y][x] && v[y][x] == color)
    {
        visited[y][x] = true;
        
        for(int i=0; i<4; i++)
        {
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0 || ny>=n || nx<0 || nx>=n)
                continue;
            else
                check(v, visited, ny, nx, color);
        }
    }
}


int main()
{
    cin >> n;
    vector<vector<int>> vno(n, vector<int>(n, 0));
    vector<vector<int>> vyes(n, vector<int>(n, 0));
    string s;

    for(int i=0; i<n; i++)
    {
        cin >> s;
        for(int j=0; j<n; j++)
        {
            if(s[j] == 'R')
            {
                vno[i][j]=0;
                vyes[i][j]=0;
            }
            else if (s[j] == 'G')
            {
                vno[i][j]=1;
                vyes[i][j]=0; //구분x
            }
            else if (s[j] == 'B')
            {  
                vno[i][j]=2;
                vyes[i][j]=2;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!N_visited[i][j])
            {
                check(vno, N_visited, i, j, vno[i][j]);
                N_cnt[vno[i][j]]++;
            }

            if(!Y_visited[i][j])
            {
                check(vyes, Y_visited, i, j, vyes[i][j]);
                Y_cnt[vyes[i][j]]++;

            }
        }
    }

    cout << N_cnt[0]+N_cnt[1]+N_cnt[2] << " " << Y_cnt[0]+Y_cnt[2];

    return 0;
}