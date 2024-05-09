// Problem: D - String Bags
// Contest: AtCoder - 	Toyota Programming Contest 2024#3（AtCoder Beginner Contest 344）
// URL: https://atcoder.jp/contests/abc344/tasks/abc344_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
dp[i][j] 使用前i个组，拼成str[0, j]所需最小费用
cst1 = dp[i-1][j]
cst2 = min(dp[i-1][j-len of str] + 1 if str fit for str in bag)
O(100 * 100 * 10 * 10) = 1e6
*/

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
const int N = 100;
int dp[N][N + 1];
int main()
{
	string t; cin >> t;
	int n; cin >> n;
	vector<vector<string>> bags(n);
	for (int i = 0; i < n; i++)
	{
		int m; cin >> m;
		while(m--)
		{
			string s; cin >> s;
			bags[i].emplace_back(s);
		}
	}
	memset(dp, -1, sizeof dp);
	for (int j = 0; j <= t.size(); j++)
	{
		for (string & s : bags[0])
		{
			if (s == t.substr(0, j)) dp[0][j] = 1;
		}	
	}
	for (int i = 0; i < n; i++) dp[i][0] = 0;

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= t.size(); j++)
		{
			if (dp[i - 1][j] != -1) dp[i][j] = dp[i - 1][j];
			for (string & s : bags[i])
			{
				if (s.size() > j) continue;
				if (t.substr(j - s.size(), s.size()) != s) continue;
				if (dp[i - 1][j - s.size()] != -1)
				{
					int cst = dp[i - 1][j - s.size()] + 1; //cout << t.substr(j - s.size(), s.size())<<'-'<<s <<' ';
					if (dp[i][j] != -1)
						dp[i][j] = min(dp[i][j], dp[i - 1][j - s.size()] + 1);
					else
						dp[i][j] = dp[i - 1][j - s.size()] + 1;
				}
			}
		}
	}
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= t.size(); j++) 
			cout << dp[i][j] << ' ';
		cout << endl;
	}
	*/	
	cout << dp[n - 1][t.size()];
}