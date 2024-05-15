// Problem: D - Divide Interval
// Contest: AtCoder - AtCoder Beginner Contest 349
// URL: https://atcoder.jp/contests/abc349/tasks/abc349_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int N = 60;
int main()
{
	ll l, r; cin >> l >> r;
	int m = 0;
	vector<ll> ls, rs;
	ll cur = l;
	while (cur != r)
	{
		for (int i = N; i >= 0; i--)
		{
			ll div = 1ll << i;
			if (cur % div == 0 && cur + div <= r)
			{
				ls.push_back(cur),
				rs.push_back(cur + div),
				cur = cur + div;
				break;
			}
		}
	}
	cout << ls.size() << endl;
	for (int i = 0; i < ls.size(); i++)
		cout << ls[i] << ' ' << rs[i] << endl;
}