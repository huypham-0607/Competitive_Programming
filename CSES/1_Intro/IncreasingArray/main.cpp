#include <bits/stdc++.h>

using namespace std;

unsigned long long n,pre,cur,ans=0;

int main()
{
    cin >> n;
    cin >> pre;
    for (int i=1; i<n; i++){
        cin >> cur;
        if (cur<pre){
            ans += pre-cur;
        }
        else{
            pre = cur;
        }
    }
    cout << ans;
    return 0;
}
