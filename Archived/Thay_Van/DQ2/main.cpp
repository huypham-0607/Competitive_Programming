#include <iostream>
#include <stdio.h>
using namespace std;

int n;

long long s(int n){
    if (n == 0) return 0;
    if (n % 2 == 0)
        return -1*n+s(n-1);
    else return n+s(n-1);
}

int main()
{
    freopen("DQ2.INP","r",stdin);
    freopen("DQ2.OUT","w",stdout);
    cin >> n;
    cout << s(n);
    return 0;
}
