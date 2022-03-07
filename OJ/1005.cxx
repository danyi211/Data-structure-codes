/*
  1-D polynomial
 */

#include<stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

int main(){
    // n = highest order
    int n, x0, i, j, c;
    scanf("%d %d", &x0, &n);

    int *pol = (int *)malloc( (n+1) * sizeof(int));
    for (i = 0; i <= n; i++){
        cin >> pol[i];
    }

    c = pol[n];
    for (i = n-1; i>=0; i--){
        c = c * x0 + pol[i];
    }

    printf("%d\n", c);
    free(pol);
    
    return 0;
}
