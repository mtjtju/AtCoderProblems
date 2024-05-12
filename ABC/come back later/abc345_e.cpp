// Problem: E - Colorful Subsequence
// Contest: AtCoder - Monoxer Programming Contest 2024（AtCoder Beginner Contest 345）
// URL: https://atcoder.jp/contests/abc345/tasks/abc345_e
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
// Author: ACCAT
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <string.h>
using namespace std;

const int N = 2e5 + 1;
const int K = 501;
using ll = long long;
using pli = pair<ll, int>;
int clr[N];
int val[N];
ll dp[N][K][2];
int dpclr[N][K][2];
int main()
{
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> clr[i] >> val[i];
    }
    memset(dp, -1, sizeof dp);
    memset(dpclr, -1, sizeof dpclr);
    dp[0][0][0] = 0;
    dp[0][1][0] = val[0]; dpclr[0][1][0] = clr[0];
}