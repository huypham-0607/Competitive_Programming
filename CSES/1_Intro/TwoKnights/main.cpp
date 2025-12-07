#include <bits/stdc++.h>

using namespace std;

unsigned long long n,init;

int main()
{
    cin >> n;
    init = 48;
    for (unsigned long long i=1; i<=n; i++){
        if (i==1) cout << 0 << endl;
        else if (i==2) cout << 6 << endl;
        else if (i==3) cout << 28 << endl;
        else if (i==4) cout << 96 << endl;
        else {
            unsigned long long del = init + 10*4*(i-4);
            del += (i-4)*(i-4)*8;
            unsigned long long ans = i*i*(i*i-1);
            ans-=del;
            ans = ans/2;
            cout << ans << endl;
        }
    }
    return 0;
}
