#include <bits/stdc++.h>

using namespace std;

map <int,int> m;
int x,n,c;

int main()
{
    cin >> n;
    c=0;
    while (n--){
        cin >> x;
        if (m.count(x)==0) c++;
        m[x] = 1;
    }
    cout << c;
    return 0;
}
