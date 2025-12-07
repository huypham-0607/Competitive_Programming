#include <bits/stdc++.h>

using namespace std;
int t,a,b,c,l,h;

int main()
{
    cin >> t;
    for (int k =0; k<t; k++){
        cin >> a >> b >> c;
        l = min(min(a,b),min(a,c));
        h = max(max(a,b),max(a,c));
        if (a!=l && a!=h) cout << a <<"\n";
        if (b!=l && b!=h) cout << b <<"\n";
        if (c!=l && c!=h) cout << c <<"\n";
    }
    return 0;
}
