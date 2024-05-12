// Problem: D - Popcount and XOR
// Contest: AtCoder - AtCoder Beginner Contest 347
// URL: https://atcoder.jp/contests/abc347/tasks/abc347_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Author: ACCAT
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
using ll = long long;

int bits(ll x)
{
    int res = 0;
    while (x)
        x -= x & -x,
        res++;
    return res;
}
int main ()
{
    int a, b; ll C;  cin >> a >> b >> C;
    int ones = bits(C); 
    if (ones < abs(a - b) || (ones - abs(a - b)) % 2 != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    int k = max(a, b) - abs(a - b) - (ones - abs(a - b)) / 2;
    a -= k, b -= k; 
    ll A = 0, B = 0;
    for (int i = 0; i < 60; i++)
    {
        ll one = 1ll << i;
        if (C & one)
        {
            if (a > 0)
                A += one,
                a--;
            else if (b > 0)
                B += one,
                b--;
        }
        else
            if (k > 0)
                A += one,
                B += one, 
                k--;
    }
    if (a || b || k)
        cout << -1 << endl;
    else
        cout << A << ' '<< B << endl;
    return 0;
}