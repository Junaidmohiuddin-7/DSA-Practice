#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// factorial of a number using recursion
int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    int ans = n * fact(n - 1);
    return ans;
}
int main()
{
    cout << fact(5);

    return 0;
}
// sum of first N numbers using recursion
int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    int ans = n + sum(n - 1);
    return ans;
}
int main()
{
    cout << sum(5);
    return 0;
}
// fibonacci series using recursion
int fib(int n)
{

    if (n == 0 || n == 1)
    {
        return n;
    }
    int ans = fib(n - 1) + fib(n - 2);
    return ans;
}
int main()
{
    cout << fib(4);

    return 0;
}