#include <bits/stdc++.h>
using namespace std;
 
/* vector tuple sort comp 사용 */
vector<tuple<int, int, int, string>> v;

bool comp(tuple<int, int, int, string>& a, tuple<int, int, int, string>& b)
{
    if((get<0>(a) == get<0>(b)) && (get<1>(a) == get<1>(b)) && (get<2>(a) == get<2>(b)))
        return get<3>(a) < get<3>(b);    //4. 이름 오름차순
    if((get<0>(a) == get<0>(b)) && (get<1>(a) == get<1>(b)))
        return get<2>(a) > get<2>(b);    //3. 수학 내림차순
    if((get<0>(a) == get<0>(b)))
        return get<1>(a) < get<1>(b);    //2. 영어 오름차순
 
    return get<0>(a) > get<0>(b);        //1. 국어 내림차순
} //오름차순(기본값) : <, 내림차순 : >
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;        
 
    for(int i=0; i<n; i++)
    {
        int a, b, c;
        string s;
        cin >> s >> a >> b >> c;
        v.push_back(make_tuple(a, b, c, s));
    }
    
    sort(v.begin(), v.end(), comp);
    
    for(int i=0; i<n; i++)
        cout << get<3>(v[i]) << "\n";
    return 0;
}