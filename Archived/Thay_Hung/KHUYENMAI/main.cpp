#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

long long m,t[1048576],t2[1048576],tt=0,a[40],b[40],c=0,nm;
int n,p,ndiv;
int main()
{
    freopen("KHUYENMAI.INP","r",stdin);
    freopen("KHUYENMAI.OUT","w",stdout);
    cin >> n >> m;
    ndiv = n/2;
    nm = 1<<ndiv;
    for (int i=0; i<ndiv; i++){
        cin >> a[i];
    }

    for (int i=0; i<nm;i++){
        for (int j=0; j<ndiv; j++){
            if (i&(1<<j)){
                t[i]+=a[j];
            }
        }
    }
    sort(t,t+nm);

    int p = n/2+n%2;

    for (int i=0; i<p; i++){
        cin >> b[i];
    }
    for (int i=0; i<(1<<p);i++){
        for (int j=0; j<p; j++){
            if (i&(1<<j)){
                t2[i]+=b[j];
            }
        }
    }

    c=0;
    for (int i=0; i<(1<<p); i++){
        c += upper_bound(t,t+nm,m-t2[i])-t;
    }

    cout << c;
    return 0;
}
