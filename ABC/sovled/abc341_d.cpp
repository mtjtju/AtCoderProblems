// Problem: D - Only one of two
// Contest: AtCoder - Toyota Programming Contest 2024#2（AtCoder Beginner Contest 341）
// URL: https://atcoder.jp/contests/abc341/tasks/abc341_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Author: ACCAT
// 
// Powered by CP Editor (https://cpeditor.org)
/*
二分上限计算
assume m > n
g = lcm(m, n)
m * k / m = k
m * k / n

    m * k / m + m * k / n - 2 * m * k / g
=    k + m * k / n - m * k / (g / 2)   //g / 2 >= n
>= k


*/
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll cnt(ll x, ll n, ll m)
{
    ll lcm = n * m / __gcd(n, m);
    return x / n + x / m - (x / lcm) * 2;
}
int main () 
{
    ll n, m, k; cin >> n >> m >> k;
    ll l = 1, r = max(n, m) * k + 3;
    
    while (l < r)
    {
        ll mid = l + (r - l) / 2;
        if (cnt(mid, n, m) < k)
            l = mid + 1;
        else
            r = mid;
    }

    cout << l;
}