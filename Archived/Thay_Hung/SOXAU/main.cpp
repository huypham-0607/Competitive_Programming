#include <iostream>
#include <stdio.h>
using namespace std;

int i=0,j=0,k=0,n;
unsigned long long a[1500],x,y,z,m;

unsigned long long cmp(unsigned long long a,unsigned long long b,unsigned long long c){
    unsigned long long d;
    d = (a<b)? a:b;
    d = (d<c)? d:c;
    return d;
}
int main()
{
    freopen("SOXAU.INP","r",stdin);
    freopen("SOXAU.OUT","w",stdout);
    a[0]=1;
    for (int h=1; h<1500; h++){
        x=a[i]*2;
        y=a[j]*3;
        z=a[k]*5;
        m=cmp(x,y,z);
        if (m == x){
            a[h]=x;
            i++;
        }
        if (m==y){
            a[h]=y;
            j++;
        }
        if (m==z){
            a[h]=z;
            k++;
        }
        //cout << a[h] << endl;
    }

    cin >> n;
    while (n!=0){
        cout << a[n-1] << endl;
        cin >> n;
    }
    return 0;
}
