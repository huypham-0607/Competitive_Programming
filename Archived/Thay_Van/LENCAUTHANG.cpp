#include <bits/stdc++.h>

using namespace std;

unsigned long long a[50001],n;

int main()
{
    freopen("LENCAUTHANG.INP","r",stdin);
    freopen("LENCAUTHANG.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;
    for (unsigned long long i = 3; i<=n; i++){
        a[i] = a[i-1] + a[i-2] + a[i-3];
    }
    cout << a[n];
    return 0;
}
