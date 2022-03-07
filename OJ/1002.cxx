#include<iostream>
using namespace std;

int fib(int k, int m)
{
    int sum = 0;
    if (m < k-1)
        return 0;
    else if (m == k-1 || m == k)
        return 1;
    else
        return 2 * fib(k, m-1) - fib(k, m-k-1);
    
}

int main()
{
    int k, m;
    cin >> k >> m;
    cout << fib(k, m) << endl;
}