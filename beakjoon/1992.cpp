#include <bits/stdc++.h>
using namespace std;

vector<string> v(64, "");
string video[65];
string ans = "";

void quadTree(vector<string> &v, int y, int x, int size)
{
    int next = 0; //영역이 나눠졌을 경우, 다음 영역의 크기를 저장

    for(int i=y; i<y+size; i++)
    {
        for(int j=x; j<x+size; j++)
        {
            if(v[y][x] != v[i][j])
            {
                ans += "(";
                next = size/2;
                quadTree(v, y, x, next);
                quadTree(v, y, x+next, next);
                quadTree(v, y+next, x, next);
                quadTree(v, y+next, x+next, next);
                ans += ")";
                return;
            }
        }
    }

    if(!next) //영역이 안나눠졌으면
    {
        if(v[y][x] == '0')
            ans += "0";
        else
            ans += "1";
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    
    string s;
    for(int i=0; i<n; i++)
    {
        cin >> s;
        v[i] = s;
    }
    
    quadTree(v, 0, 0, n);
    
    cout << ans;
    return 0;
}