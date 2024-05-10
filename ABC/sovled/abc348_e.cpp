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
cntLow[i]: number of lower nodes

cntLow[i] = sum(cntLow[child of i]) + children.size()
low[i] = sum(low[child of i] + cntLow[i] * Ci)
res[root] = low[root]
ups[i] = res[pa] - (low[i] + cntLow[i] * Citopa) + (totCnt - cntLow[i] - 1) * Citopa
res[i] = ups[i] + low[i]

calc cntLow
calc low
get res[root]
calc ups[i]
calc res[i]
*/