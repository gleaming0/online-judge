#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int A, B;
    cin >> A >> B;

    if(A<B)
        swap(A, B);
    
    int a=A, b=B, n=1;
    while(n!=0)
    {
        n = a%b;
        a = b;
        b = n;
    }

    int gcd = a;
    int lcm = (A*B)/gcd;
    cout << gcd << "\n" << lcm;
    
    return 0;
}