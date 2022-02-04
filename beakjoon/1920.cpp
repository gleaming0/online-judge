#include <bits/stdc++.h>
using namespace std;

void BinarySearch(int arr[], int size, int key)
{
	int s = 0;
	int e = size-1;
	int m;

	while(s<=e)
	{
		m = (s+e)/2;
		if(arr[m] == key)
		{
			cout << "1\n";
			return;
		}
		else if(arr[m] > key)
			e = m-1;
		else
			s = m+1;
	}
	cout << "0\n";
	return;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n;

	int tmp; int arr[n];
	for(int i=0; i<n; i++)
	{
		cin >> tmp;
		arr[i] = tmp;
	}

	sort(arr, arr+n);

	cin >> m;
	for(int i=0; i<m; i++)
	{
		cin >> tmp;
		BinarySearch(arr, n, tmp);
	}

	return 0;
}

//배열을 벡터로만 바꿨는데 시간초과가 왜 날까?