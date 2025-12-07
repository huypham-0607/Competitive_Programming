#include <iostream>
#include <stdio.h>
using namespace std;

int m,n;

int ucln (int a,int b){
    if (b==0) return a;
    else return ucln(b, a % b);
}

int main()
{
    freopen("DQ4.INP","r",stdin);
    freopen("DQ4.OUT","w",stdout);
    cin >> m >> n;
    cout << ucln(m,n);
    return 0;
}
