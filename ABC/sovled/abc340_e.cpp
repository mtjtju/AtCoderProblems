// Problem: E - Mancala 2
// Contest: AtCoder - KAJIMA CORPORATION CONTEST 2024（AtCoder Beginner Contest 340）
// URL: https://atcoder.jp/contests/abc340/tasks/abc340_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
1. 线段树写错两个地方，还是思想没理解
2. 题目中的逻辑翻译错误，这种细节还是要多画图多debug
3. 涉及“值”的地方记得用ll
*/

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> f, v;
vector<int> nums;

void build(int k, int l, int r)
{
        if (l == r)
        {
                f[k] = nums[l];
                return;
        }
        int mid = l + (r - l) / 2;
        build(k + k, l, mid);
        build(k + k + 1, mid + 1, r);
        f[k] = f[k + k] + f[k + k + 1];
}

void add(int k, int l, int r, int s, int e, ll x)
{
        if (l == s && r == e)
        {
                v[k] += x;
                return;
        }        
        
        f[k] += v[k] * (r - l + 1);
        v[k + k] += v[k], v[k + k + 1] += v[k], v[k] = 0;
        
        int mid = l + (r - l) / 2;
        if (e <= mid)
                add(k + k, l, mid, s, e, x);
        else if (s > mid)
                add(k + k + 1, mid + 1, r, s, e, x);
        else
                add(k + k, l, mid, s, mid, x),
                add(k + k + 1, mid + 1, r, mid + 1, e, x);
}

ll calc(int k, int l, int r, int s, int e)
{
        if (l == s && r == e)
                return f[k] + v[k] * (r - l + 1) ;
        
        f[k] += v[k] * (r - l + 1);
        v[k + k] += v[k], v[k + k + 1] += v[k], v[k] = 0;
        
        int mid = l + (r - l) / 2;
        if (e <= mid)
                return calc(k + k, l, mid, s, e);
        else if (s > mid)
                return calc(k + k + 1, mid + 1, r, s, e);
        else
                return calc(k + k, l, mid, s, mid) +
                calc(k + k + 1, mid + 1, r, mid + 1, e);
}

int main ()
{
        int n, m; 
        cin >> n >> m;
        f.reserve(n * 4);
        v.reserve(n * 4);
        for (int i = 0; i < n * 4; i++) f[i] = v[i] = 0;        
        nums.reserve(n+1);
        vector<int> ms(m);
        for (int i = 1; i < n+1; i++)
                cin >> nums[i];
        for (int i = 0; i < m; i++)
                cin >> ms[i], ms[i]++;
        build(1, 1, n);
        
        for (int i = 0; i < m; i++)
        {
                ll x = calc(1, 1, n, ms[i], ms[i]);
                add(1, 1, n, ms[i], ms[i], -x);
                int a = (ms[i] + 1) % n; if (!a) a = n;
                int laps = x / n;
                int b = a;
                b += (x % n - 1);
                add(1, 1, n, 1, n, laps);
                if (x % n != 0) 
                {
                    if (b <= n)
                        add(1, 1, n, a, b, 1);
                    else
                        add(1, 1, n, a, n, 1),
                        add(1, 1, n, 1, b - n, 1);
                }
        }
        for (int i = 1; i <= n; i++)
                cout << calc(1, 1, n, i, i) << ' ';
        cout << endl;
        return 0;
}