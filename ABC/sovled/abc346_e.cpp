// Problem: E - Paint
// Contest: AtCoder - UNIQUE VISION Programming Contest 2024 Spring(AtCoder Beginner Contest 346)
// URL: https://atcoder.jp/contests/abc346/tasks/abc346_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 2e5+1;
ll prefc[N], prefr[N];
int main()
{
	map<int, int> cs, rs;
	vector<pii> allPs; 
	int m, n, q; cin >> m >> n >> q;
	for (int i = 0; i < q; i++)
	{
		int t, x, clr; cin >> t >> x >> clr;
		if (t == 1) x  *= -1;
		allPs.emplace_back(x, clr);		
	}
	vector<pii> ps;
	for (int i = q - 1; i >= 0; i--)
	{
		int x = allPs[i].first, clr = allPs[i].second;
		if (x < 0 && !rs.count(x))
			ps.emplace_back(allPs[i]),
			rs[x] = clr;
		if (x > 0 && !cs.count(x))
			ps.emplace_back(allPs[i]),
			cs[x] = clr;
	}
	
	reverse(ps.begin(), ps.end());
	map<int, ll> res;
	for (int i = 0; i < ps.size(); i++)
	{
		prefc[i] = 0;
		prefr[i] = 0;
	}
	for (int i = 0; i < ps.size(); i++)
	{
		res[ps[i].second] += ps[i].first < 0 ? n : m;
	}
	for (int i = 0; i < ps.size(); i++)
	{
		int x = ps[i].first, clr = ps[i].second;
		if (x < 0)
			prefc[0] -= 1, prefc[i + 1] += 1;
		else
			prefr[0] -= 1, prefr[i + 1] += 1;
	}
	ll curc = 0, curr = 0;
	for (int i = 0; i < ps.size(); i++)
	{
		curc += prefc[i], curr += prefr[i];
		int x = ps[i].first, clr = ps[i].second;
		if (x < 0)
			res[clr] += curr;
		else
			res[clr] += curc; 
	}
	ll zero = 1ll * m * n;
	int k = 0; for (auto p : res) if (p.first && p.second) k++, zero -= p.second;
	res[0] = zero;
	if (zero > 0) k++;
	cout << k << endl;
	for (auto p : res) 
		if (p.second)
			cout << p.first << ' ' << p.second << endl;
}