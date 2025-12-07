#include <bits/stdc++.h>

using namespace std;

unsigned long long n,c=5,ans=0;

int main()
{
    cin >> n;
    while (c<=n){
        ans+=n/c;
        c*=5;
    }
    cout << ans;
    return 0;
}
