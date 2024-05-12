// Problem: E - Chords
// Contest: AtCoder - AtCoder Beginner Contest 338
// URL: https://atcoder.jp/contests/abc338/tasks/abc338_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Author: ACCAT
// 
// Powered by CP Editor (https://cpeditor.org)

/*
for i in [0, n-1):
    for j in [i+1, n):
        if !(ej < si || sj > ei)
            Yes
No

点下标的取值范围1e6，所以可以桶排序，线性复杂度。
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
using pii = pair<int, int>;
int main ()
{
    int n; 
    cin >> n;
    vector<int> v(2 * n + 1, 0);
    
    for (int i = 1; i < n + 1; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        v[a] = -i;
        v[b] = i;
    }
    
    stack<int> stk;
    for (int i = 1; i <= n * 2; i++)
    {
        int x= v[i];
        if (x < 0)
            stk.push(x);
        else
        {
            int t = stk.top();
            if (x != -t)
            {
                cout << "Yes";
                return 0;
            }
            stk.pop();
        }
    }
    cout << "No";
    return 0;
}