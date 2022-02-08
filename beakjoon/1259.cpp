#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string num;
    cin >> num;

    while(num != "0")
    {
        int len = num.length();
        bool isP = true;

        for(int i=0; i<len/2; i++)
        {
            if(num[i] != num[len-i-1])
            {
                isP = false;
                break;
            }
        }

        if(isP)
            cout << "yes\n";
        else
            cout << "no\n";
            
        cin >> num;
    }
    return 0;
}