#include <iostream>
#include <stdio.h>
using namespace std;

int n=0,x,a[20],i=0;

void m(int so, int &n){
    if (so == 0) {
        return;
    }
    else {
        a[n]= so % 10;
        m(so/10, ++n);
    }
}


int main()
{
    freopen("DQ3.INP","r",stdin);
    freopen("DQ3.OUT","w",stdout);
    cin >> x;
    m(x,n);
    a[n] = 10;
    while (a[i] == 0){
        i++;
    }
    for (i; i<n; i++){
        cout << a[i];
    }
    return 0;
}
