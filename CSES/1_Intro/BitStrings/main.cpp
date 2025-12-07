#include <bits/stdc++.h>
#define num 1000000007

using namespace std;

unsigned long long n,ans=1;

int main()
{
    cin >> n;
    while (n--){
        ans*=2;
        ans = ans%num;
    }
    cout << ans;
    return 0;
}
