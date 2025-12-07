#include <bits/stdc++.h>
#define div 1000000007
#define mx 1000000
using namespace std;

int a[mx],n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    a[0] = 1;
    //for (int i=1; i<=6; i++) a[i] = 1;
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=i-1; j>=0 && j>=i-6; j--){
            a[i]= (a[i] + a[j])%div;
        }
    }

    cout << a[n];
    return 0;
}
