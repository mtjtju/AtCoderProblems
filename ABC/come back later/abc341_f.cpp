// Problem: F - Breakdown
// Contest: AtCoder - Toyota Programming Contest 2024#2（AtCoder Beginner Contest 341）
// URL: https://atcoder.jp/contests/abc341/tasks/abc341_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Author: ACCAT
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
vector<vector<int>> ajList;
vector<int> weights;
vector<ll> as;
vector<ll> dfsdp;

ll GetScore(int vv, const vector<ll> & items, const vector<ll> & wts, int space)
{
    if (items.empty()) return 0;
    vector<vector<ll>> dp(items.size(), vector<ll>(space + 1));
    for (int i = 0; i < items.size(); i++)
    {
        int v = items[i], w = wts[i];
        for (int j = w; j <= space; j++)
        {
            ll noI = i > 0 ? dp[i - 1][j] : 0;
            ll yesI = i > 0 ? dp[i - 1][j - w] + v : v;
            dp[i][j] = max(noI, yesI);
        }
    }

    if (items.empty()) return 0;
    else return dp[items.size() - 1][space];
}

void dfs(int v, int pa)
{
    if (dfsdp[v]) return;
    vector<ll> items, wts;
    
    for (int u : ajList[v])
    {
        if (u == pa)
            continue;
        if (weights[v] <= weights[u])
            continue;
        if (!dfsdp[u])
            dfs(u, v);
        items.emplace_back(dfsdp[u]);
        wts.emplace_back(weights[u]);
    }
    dfsdp[v] = GetScore(v, items, wts, weights[v] - 1) + 1;
}

int main () 
{
    int n, m; cin >> n >> m;
    ajList.clear(); ajList.resize(n + 1);
    weights.clear(); weights.resize(n + 1);
    as.clear(); as.resize(n + 1);
    dfsdp.clear(); dfsdp.resize(n + 1);
    fill(dfsdp.begin(), dfsdp.end(), 0);
    
    for (int i = 0; i < m; i++)
    {
        int v, u; cin >> v >> u;
        ajList[v].emplace_back(u);
        ajList[u].emplace_back(v);
    }
    
    for (int i = 1; i <= n; i++)
        cin >> weights[i];
    for (int i = 1; i <= n; i++)
        cin >> as[i];

    ll res = 0;
    for (int i = 1; i <= n; i++)
        if (dfsdp[i] == 0)
            dfs(i, i);
    for (int i = 1; i <= n; i++)
        res += as[i] * dfsdp[i];
    cout << res;
    return 0;
}