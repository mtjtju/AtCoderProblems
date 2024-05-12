// Problem: D - Super Takahashi Bros.
// Contest: AtCoder - KAJIMA CORPORATION CONTEST 2024（AtCoder Beginner Contest 340）
// URL: https://atcoder.jp/contests/abc340/tasks/abc340_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Author: ACCAT
// 
// Powered by CP Editor (https://cpeditor.org)

#include <queue>
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using pq = priority_queue<pii, vector<pii>, greater<pii>>;

vector<vector<pii>> buildGraph(int n)
{
    vector<vector<pii>> res(n+1);
    for (int i = 1; i < n; i++)
    {
        int a, b, x; 
        cin >> a >> b >> x;
        res[i].emplace_back(a, i + 1);
        res[i].emplace_back(b, x);
    }
    return res;
}

vector<ll> buildCost(int n, int start)
{
    vector<ll> res(n+1, LLONG_MAX);
    res[start] = 0;
    return res; 
}

void dijkstra(vector<vector<pii>> & ajList, vector<ll> & cst)
{
    pq q;
    q.push(make_pair(0, 1));
    while (!q.empty())
    {
        pii edge = q.top();
        q.pop();
        ll d = edge.first, v = edge.second; 
        if (d > cst[v]) 
            continue;
        for (pii e : ajList[v])
        {
            ll w = e.first, u = e.second;
            ll d2u = d + w;
            if (cst[u] > d2u)
                cst[u] = d2u,
                q.push(make_pair(d2u, u));
        }
    } 
}

int main()
{
    int n;
    cin >> n;
    vector<vector<pii>> ajList = buildGraph(n);
    vector<ll> cst = buildCost(n, 1);
    dijkstra(ajList, cst);
    cout << cst[n];
    return 0;
}