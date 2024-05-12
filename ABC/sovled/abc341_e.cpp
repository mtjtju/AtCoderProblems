// Problem: E - Alternating String
// Contest: AtCoder - Toyota Programming Contest 2024#2（AtCoder Beginner Contest 341）
// URL: https://atcoder.jp/contests/abc341/tasks/abc341_e
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// Author: ACCAT
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <string.h>
using namespace std;

const int N = 500001;
int f[4 * N];
char as[N]; // as[i]: num[i] != num[i+1]  i = 1~n-1

void build(int k, int l, int r)
{
    if (l == r)
    {
        f[k] = as[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(k + k, l, mid); build(k + k + 1, mid + 1, r);
    f[k] = f[k + k] + f[k + k + 1];
}
void inc(int k, int l, int r, int x, int idx)
{
    f[k] += x;
    if (l == r)
    {
        return;
    }
    int mid = l + (r - l) / 2;
    if (idx <= mid) inc(k + k, l, mid, x, idx);
    else inc(k + k + 1, mid + 1, r, x, idx);
}
int calc(int k, int l, int r, int s, int e)
{
    if (l == s && r == e)
    {
        return f[k];
    }
    int mid = l + (r - l) / 2;
    if (s > mid) 
        return calc(k + k + 1, mid + 1, r, s, e);
    else if (e <= mid) 
        return calc(k + k, l, mid, s, e);
    else 
        return calc(k + k, l, mid, s, mid) + 
                calc(k + k + 1, mid + 1, r, mid + 1, e);
}
int main () 
{
    int n, q; cin >> n >> q;
    memset(f, 0, (n + 1) * 4 * sizeof (int));
    memset(as, 0, (q + 1) * sizeof (char));
    string num; cin >> num;
    for (int i = 1; i < n; i++)
    {
        as[i] = num[i-1] == num[i] ? 0 : 1;
    }
    build(1, 1, n);
    int j = 1;
    while(q--)
    {
        int t, l, r; cin >> t >> l >> r;
        if (t == 1)
        {
            if (l - 1 > 0)
            {
                int val = calc(1, 1, n, l - 1, l - 1) == 1 ? -1 : 1;
                inc(1, 1, n, val, l - 1);
            }
            if (r < n)
            {
                
                int val = calc(1, 1, n, r, r) == 1 ? -1 : 1;
                inc(1, 1, n, val, r);
            }
        }
        else
        {
            if (l == r)
            {
                cout << "Yes" << endl;
                continue;
            }
            int cnt = calc(1, 1, n, l, r - 1);
            
            string res = cnt == r - 1 - l + 1 ? "Yes" : "No";
            cout << res << endl;
        }
        j++;
    }
}