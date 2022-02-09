#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; i++)
		v.push_back(i);

	cout << "<";

	int idx=0;
	while(v.size() > 1) //마지막 하나는 따로 출력!
	{
		idx += (k-1);
		while(idx>=v.size())
			idx -= v.size();
		//cout << "now idx=" << idx << ", v.size=" << v.size() << ", erase " << v[idx] << "\n";
		cout << v[idx] << ", ";
		v.erase(v.begin()+idx);
	}

	cout << v[0] << ">";
	return 0;
}

//(idx>=v.size())부분에서 1번만 빼줘서 자꾸 오류가 났었다.
//1번만 빼는게 아니라, (idx<v.size())일 때까지 계속 빼줘야 한다!
//+) 원형큐로 다시 풀어보면 좋을듯!