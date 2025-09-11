/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int sqrts(int n)
{
    int s = 0;
    int e = n;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (mid * mid > n)
        {
            e = mid - 1;
        }
        else if (mid * mid <= n)
        {
            ans = mid;
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    int n = 63;
    double ans = sqrts(n);
    int precision = 8;
    double step = 0.1;
    while (precision--)
    {
        double j = ans;
        while (j * j <= n)
        {
            ans = j;
            j = step + j;
        }
        step = step / 10;
    }
    cout << setprecision(10) << ans;

    return 0;
}