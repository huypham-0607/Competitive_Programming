#include <bits/stdc++.h>

using namespace std;
int a,b,t;
int main()
{
    cin >> t;
    while (t--){
        cin >> a >> b;
        if (a>b) swap(a,b);
        if (a*2<b) cout << "NO" << endl;
        else {
            a%=3;
            b%=3;
            if ((a==b && a!=0) || (a==0 && b!=0) || (b==0 && a!=0)) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
    return 0;
}
