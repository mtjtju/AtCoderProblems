// Problem: D - Island Tour
// Contest: AtCoder - AtCoder Beginner Contest 338
// URL: https://atcoder.jp/contests/abc338/tasks/abc338_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Author: ACCAT
// 
// Powered by CP Editor (https://cpeditor.org)

// tot[i]的定义不清晰，所以写成了tot[b+1] -= cst，其实是tot[b] -= cst
// tot[b]指的就是[b,b+1]的值

// imos比第一版好写
//    第一版：for step in steps: for edge in edges: calc(edge)
//    imos: 每一个边直接算出全部步骤的贡献，相对第一版交换了内外循环。
//            for edge in edges: for step in steps: calc(edge)
// cst[i]指对比curRes，切开i~i+1产生的贡献
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
using ll = long long;
int main () 
{
    int n, m; cin >> n >> m;
    vector<ll> cst(n+1, 0);
    int a = -1, b = -1;
    ll curRes = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> b;
        if (a != -1)
        {
            int aa = min(a, b), bb = max(a, b);
            curRes += bb - aa;
            int k = n - 2 * (bb - aa);
            cst[aa] += k;
            cst[bb] -= k;
        }
        a = b;
    }
    for (int i = 1; i < n; i++)
        cst[i] += cst[i-1];
    ll res = curRes;
    for (int i = 1; i < n; i++)
    {
        res = min(res, curRes + cst[i]);
    }
    cout << res;
    return 0;
}
/* 第一版
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
using ll = long long;
int main () 
{
    int n, m; cin >> n >> m;
    vector<ll> tot(n+2, 0);
    vector<ll> cnt(n+2, 0);
    vector<int> ms(m, 0);
    for (int i = 0; i < m; i++)
        cin >> ms[i];
    ll res = 0;  
    for (int i = 0; i < m-1; i++)
    {
        int a = ms[i], b = ms[i+1];
        if (a > b) swap(a, b);
        int cst = b - a; 
        res += cst;
        tot[a] += cst;
        tot[b] -= cst;
        cnt[a]++;
        cnt[b]--;
    }

    for (int i = 1; i < n; i++)
        tot[i] += tot[i-1],
        cnt[i] += cnt[i-1];      
    
    ll oriRes = res;
    for (int i = 1; i < n; i++)
    {
        ll cutcst = oriRes - tot[i] * 2 + 1ll * n * cnt[i];
        res = min(res, cutcst);
    }
    cout << res;
    return 0;
}
*/

