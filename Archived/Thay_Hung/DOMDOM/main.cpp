#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;


int t[100000],b[100000],a[500000],x,y,n,h;

int main()
{
    freopen("DOMDOM.INP","r",stdin);
    freopen("DOMDOM.OUT","w",stdout);
    cin >> n >> h;
    for (int i=0; i<n; i++){
        if (i % 2 == 0) cin >> b[i/2];
        else cin >> t[i/2];
    }

    sort(t,t+n/2);
    sort(b,b+n/2);

    for (int i=1; i<=h; i++){
        x = n/2 - (lower_bound(b,b+n/2,i)-b);
        y = n/2 - (lower_bound(t,t+n/2,h-i+1)-t);
        a[i] = x+y;
    }

    sort(a+1,a+h);

    cout << upper_bound(a+1,a+h,a[1])-(a+1) << " " << a[1];
    return 0;
}
