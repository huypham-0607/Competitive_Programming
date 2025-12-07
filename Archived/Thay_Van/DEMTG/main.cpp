#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n,i,j,k,t=0;
int * x;

void nhap(int a[1000]){
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
}

int main()
{
    freopen("DEMTG.INP","r",stdin);
    freopen("DEMTG.OUT","w",stdout);
    cin >> n;
    int a[n],b[n],c[n];
    nhap(a);
    nhap(b);
    nhap(c);
    sort(c,c+n);

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            x=lower_bound(c,c+n,abs(a[i]-b[j])+1);
            if (x-c!=n){
                t+=(upper_bound(x,c+n,a[i]+b[j]-1) - x);
                cout << t << endl;
            }
        }
    }
    cout << t;
    return 0;
}
