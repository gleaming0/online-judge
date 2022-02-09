#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
        q.push(i);

    while(q.size()>1)
    {
        //맨 위 카드 버리기
        q.pop();

        //맨 위 카드 제일 아래로 옮기기
        int bottom = q.front();
        q.pop();
        q.push(bottom);
    }

    cout << q.front();
    return 0;
}