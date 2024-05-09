// Problem: D - Medicines on Grid
// Contest: AtCoder - Toyota Programming Contest 2024#4（AtCoder Beginner Contest 348）
// URL: https://atcoder.jp/contests/abc348/tasks/abc348_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
vector<vector<char>> g;
vector<vector<int>> med;
vector<vector<bool>> vstd;
vector<pii> medToGo;
int rs[4] = {0, 0, 1, -1};
int cs[4] = {1, -1, 0, 0};
bool res = false;

int m, n, N;

void readG()
{
	cin >> m >> n;
	g.resize(m, vector<char>(n, ' '));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> g[i][j];
			if (g[i][j] == 'S')
				medToGo.emplace_back(i, j);
		}
			
}

void bfs()
{
	if (medToGo.empty())
		return;
		
	auto [r, c] = medToGo.back();
	medToGo.pop_back();
	if (!med[r][c]) return;
	int medCnt = med[r][c];
	med[r][c] = 0;
	
	vstd = vector<vector<bool>>(m, vector<bool>(n, false));
		
	queue<tiii> q;
	q.emplace(r, c, medCnt);
	vstd[r][c] = true;
	while (!q.empty() && medCnt)
	{
		auto [rr, cc, mm] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nxtr = rr + rs[i], nxtc = cc + cs[i];
			if (nxtr >= 0 && nxtr < m && nxtc >= 0 && nxtc < n 
				&& !vstd[nxtr][nxtc] && g[nxtr][nxtc] != '#' && mm > 0)
			{
				vstd[nxtr][nxtc] = true;
				q.emplace(nxtr, nxtc, mm - 1);
				if (med[nxtr][nxtc] > 0)
					medToGo.emplace_back(nxtr, nxtc);
				if (g[nxtr][nxtc] == 'T')
					res = true;
			}
		}
	}
}

int main()
{
	res = false;
	readG();
	cin >> N;
	med = vector<vector<int>>(m, vector<int>(n, 0));

	for (int i = 0; i < N; i++)
	{
		int r, c; cin >> r >> c;
		cin >> med[r-1][c-1];
	}
	while(medToGo.size()) bfs();
	if (res) cout << "Yes";
	else cout << "No";
}