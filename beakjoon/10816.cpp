#include <bits/stdc++.h>
using namespace std;

int arr[20000002]; //-10,000,000 -> arr[0], 0 -> arr[10000001], 10,000,000 -> arr[20000001]
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        arr[a+10000000]++;
    }
    
    int m;
    cin >> m;
    for(int i=0; i<m; i++)
    {
       int a;
       cin >> a;
       cout << arr[a+10000000] << " ";
    }
    
    return 0;
}