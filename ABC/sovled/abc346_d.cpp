// Problem: D - Gomamayo Sequence
// Contest: AtCoder - UNIQUE VISION Programming Contest 2024 Spring(AtCoder Beginner Contest 346)
// URL: https://atcoder.jp/contests/abc346/tasks/abc346_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <string.h>
#include <limits.h>
using namespace std;
using ll = long long;

const int N = 2e5;
ll dleft[N][2]; // 0~i, 变成ok的以j结尾的串需要的cst
ll dright[N][2]; // i~n-1, 变成ok的以j结尾的串需要的cst
int cs[N];
int main()
{
	int n; string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> cs[i];
	
	dleft[0][0] = s[0] == '0' ? 0 : cs[0];
	dleft[0][1] = s[0] == '1' ? 0 : cs[0];
	for (int i = 1; i < n; i++)
		dleft[i][0] = s[i] == '0' ? dleft[i-1][1] : dleft[i-1][1] + cs[i],
		dleft[i][1] = s[i] == '1' ? dleft[i-1][0] : dleft[i-1][0] + cs[i];
	dright[n-1][0] = s[n-1] == '0' ? 0 : cs[n-1];
	dright[n-1][1] = s[n-1] == '1' ? 0 : cs[n-1];
	for (int i = n-1; i >= 0; i--)
		dright[i][0] = s[i] == '0' ? dright[i+1][1] : dright[i+1][1] + cs[i],
		dright[i][1] = s[i] == '1' ? dright[i+1][0] : dright[i+1][0] + cs[i];
		
	// enumerate 00 or 11
	ll res = LLONG_MAX;
	for (int i = 0; i < n - 1; i++)
	{
		//cout << i << ' ';
		// 00
		ll curres = 1ll * (s[i] != '0') * cs[i] + (s[i+1] != '0')* cs[i+1];
		
		if (i > 0) curres += dleft[i-1][1];
		if (i < n-2) curres += dright[i+2][1];//cout << curres << ' ';
		res = min(res, curres);
		
		// 11
		curres =  1ll * (s[i] != '1') * cs[i] + (s[i+1] != '1')* cs[i+1];
		if (i > 0) curres += dleft[i-1][0];
		if (i < n-2) curres += dright[i+2][0];
		res = min(res, curres);
		//cout << curres << ' ' << endl;
	}
	cout << res << endl;
	return 0;
}