#include <bits/stdc++.h>
using namespace std;

int n, total = 0;
int answer = 0;
void ParametricSearch(vector<int> &v, int left, int right)
{
    int mid = 0;
    while(left<right)
    {
        mid = (left+right)/2;
        int summ = 0;
        for(int i=0; i<n; i++)
        {
            if(v[i] <= mid)
                summ += v[i];
            else
                summ += mid;
        }
        //cout << "(left, mid, right) : (" << left << ", " << mid << ", " << right << ") and summ : " << summ << endl;
        if(summ <= total)
        {
            left = mid+1;
            answer = max(answer, mid);
        }
        else
        {
            right = mid;
        }
        //cout << "answer : " << answer << endl;
    }
    cout << answer;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    vector<int> v(n, 0);
    int summ = 0;

    for(int i=0; i<n; i++)
    {
        cin >> v[i];
        summ += v[i];
    }

    cin >> total;
    sort(v.begin(), v.end());

    if(summ <= total)   // 조건1 : 그대로 배정, 가장 큰 v[n-1] 출력
        cout << v[n-1];
    else                // 조건2 : 상한액 구하기
    {
        if(v[0]*n > total) // 가장 작은 수인 v[0]*n > total --> v[0] > 상한값 --> 그냥 total/n = 상한값
        {
            //ParametricSearch(v, 0, v[n-1]);
            cout << total/n;
        }
        else ParametricSearch(v, v[0], v[n-1]);
    }

    return 0;
}