#include <iostream>
#include <stdio.h>
using namespace std;

int x,y;

long long luythua(int x,int y){
    if (y==0) return 1;
    else return x*luythua(x,y-1);
}

int main()
{
    freopen("DQ1.INP","r",stdin);
    freopen("DQ2.OUT","w",stdout);
    cin >> x >> y;
    cout << luythua(x,y);
    return 0;
}
