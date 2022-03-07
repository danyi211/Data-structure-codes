#include<iostream>
using namespace std;

int main()
{
    int i, j, len=3;
    int a[len];
    for (i = 0; i < len; i++) cin >> a[i];
    
    for (i = 0; i < len -1; i++) {
        int max = i;
        for (j = i+1; j < len; j++)
            if (a[j] > a[max]) max = j;
        
        swap(a[i], a[max]);
    }

    for (i = 0; i < len; i++) cout << a[i] << " ";
    cout << endl;

}