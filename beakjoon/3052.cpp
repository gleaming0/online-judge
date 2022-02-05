#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int cnt = 0;
bool equall = false;

bool comp(int a, int b)
{
	if(a==b)
		equall = true;
	return a<b;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for(int i=0; i<10; i++)
	{
		int n;
		cin >> n;
		v.push_back(n%42);
	}

	sort(v.begin(), v.end(), comp);

	for(int i=0; i<10; i++)
	{
		if(v[i] != v[i+1])
			cnt++;
	}

	if(equall && cnt==0) //나머지가 다 똑같을 때(예제 입력 2)
		cout << cnt+1;
	else
		cout << cnt;

	return 0;
}