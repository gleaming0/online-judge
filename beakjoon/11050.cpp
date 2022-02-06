/*
	이항계수
	nCk = n! / (n-k)!k! (단, 0<=k<=n)
*/

#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
	int ans = 1;
	for(int i=2; i<n+1; i++)
		ans *= i;
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	int N = factorial(n);
	int K = factorial(k);
	int N_K = factorial(n-k);
	cout << N/N_K/K;
    
	return 0;
}