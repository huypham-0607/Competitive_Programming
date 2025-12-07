#include <bits/stdc++.h>

using namespace std;

int n,l,r,minl,minr,a[100000],t;

int main()
{
    freopen("DCLN.INP","r",stdin);
    freopen("DCLN.OUT","w",stdout);
    cin >> n;
    for (int i =0; i<n; i++){
        cin >> a[i];
        t += a[i];
    }

    //l[0] = 0;
    //r[n-1] = 0;

    //1-9
    //2-10
    l=0;
    r=t;
    minl = 0;
    minr = 0;
    for (int i =0; i<n-1; i++){
        l+=a[i];
        r-=a[i];
        minl = min(minl,l);
        minr = min(minr,r);
        //cout << minl << " " << minr << endl;
    }

    cout << t-minl-minr; //<< endl << minl << endl << minr;

    return 0;
}
