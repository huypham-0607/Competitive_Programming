#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;
int i,n,x;
long long t,a[40000];
string s,st;
int main()
{
    freopen("DAYSO.INP","r",stdin);
    freopen("DAYSO.OUT","w",stdout);
    a[0] = 0;
    i=1;
    while (i < 32009){
        s+=to_string(i);
        a[i] +=a[i-1]+s.size();
        i++;
    }
    t=i-1;
    cin >> n;
    for (i=0; i<n; i++){
        cin >> x;
        cout << s[x-a[(lower_bound(a,a+t,x)-a)-1]-1] << endl;
    }
    return 0;
}
