#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    //소수 만들기(소수o : 0, 소수x : 1)
    arr[1] = 1;

    int idx=2;
    while(idx < 32) //32*32=1024
    {
        int i=2;
        while(idx*i < 1001)
        {
            arr[idx*i] = 1; //소수아닌 것
            i++;
        }
        idx++;
    }

    int n, a;
    int ans=0;
    
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        if(arr[a] == 0)
            ans++;
    }

    cout << ans;
    return 0;
}

//처음에 (idx<11)로 생각해서 틀렸다. 이 경우에는 11단 이상의 수를 검증하지 않는다. (ex. 11*11=121로 소수가 아니지만, 아예 확인을 안함)
//입력이 100 이하의 자연수면 (idx<11)까지 해도 되지만, 1000이하의 자연수이므로 (idx<32)까지 해야 함! (32*32=1024)
// +)시간제한이 2초니까 나머지를 일일이 구해봐도 괜찮을 듯?!