#include <bits/stdc++.h>

using namespace std;

unsigned long long t,level,i,j;

int main()
{
    cin >> t;
    for (int k=0; k<t; k++){
        cin >> i >> j;
        level = max(i,j);
        unsigned long long ans = level-1;
        ans = ans*ans;
        if (level%2 == 1) swap(i,j);
        ans = ans + i + (level - j);
        cout << ans << endl;
    }
    return 0;
}
