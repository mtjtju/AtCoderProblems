// Problem: E - Minimize Sum of Distances
// Contest: AtCoder - Toyota Programming Contest 2024#4（AtCoder Beginner Contest 348）
// URL: https://atcoder.jp/contests/abc348/tasks/abc348_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
res[i]: tot dist from all other nodes
low[i]: tot dist from all lower nodes
ups[i]: tot dist from all upper nodes

clow[i]: sum of C of tree i
cntLow[i]: number of lower nodes

clow[i] = sum(clow[child]) + ci
cntLow[i] = sum(cntLow[child of i]) + children.size()

low[i] = sum(low[child] + clow[child])
res[root] = low[root]
ups[i] = res[pa] - (low[i] + clow[i]) + totc - clow[i]
res[i] = ups[i] + low[i]

calc clow
calc cntlow
calc low
get res[root]
calc ups[i]
calc res[i]
*/
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 1;

ll res[N], low[N], ups[N], clow[N];
int cs[N], cntLow[N];
vector<vector<int>> t;

ll calcClow(int u, int pa)
{
	ll res = 0;
	for (int v : t[u])
		if (v != pa)
			res += calcClow(v, u);
	return clow[u] = res + cs[u];
}

int calcCntLow(int u, int pa)
{
	int res = 0;
	for (int v : t[u])
		if (v != pa)
			res += calcCntLow(v, u);
	return cntLow[u] = res + 1;
}

ll calcLow(int u, int pa)
{
	ll res = 0;
	for (int v : t[u])
		if (v != pa)
			res += calcLow(v, u) + clow[v];
	return low[u] = res;	
}

int main()
{
	int n; cin >> n;
	t = vector<vector<int>>(n + 1, vector<int>());
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		t[u].emplace_back(v);
	}
	for (int i = 1; i <= n; i++)
		cin >> cs[i];
		
	int root = 1;
	
	calcClow(root, -1); 
	calcCntLow(root, -1); 
	calcLow(root, -1);
	res[1] = low[1];
	//calcUps(root, -1); 
	//calcRes(root, -1);
	for (int i = 1; i <= n; i++) cout << low[i] << ' '; cout << endl;
	ll minRes = LLONG_MAX;
	for (int i = 1; i <= n; i++)
		minRes = min(minRes, res[i]);
}