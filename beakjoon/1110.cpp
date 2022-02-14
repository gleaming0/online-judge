#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, cnt=0;
    cin >> n;
 
    int each_sum, new_n;
    new_n = n;
 
    while(1)
    {
        //각 자리의 숫자 더하기
        if(new_n < 10)
            each_sum = new_n%10;
        else
            each_sum = new_n/10 + new_n%10;
 
        //주어진 수의 가장 오른쪽 자리 수와 앞에서 구한 가장 오른쪽 자리 수 이어 붙이기
        new_n = (new_n%10 * 10) + (each_sum%10);
 
        cnt++;
        if(n==new_n)
        {
            cout << cnt;
            break;
        }
    }
    return 0;
}