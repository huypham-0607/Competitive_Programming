#include <bits/stdc++.h>

using namespace std;

int add,n;

int main()
{
    cin >> n;
    if (n==1) cout << "1";
    else if (n<4) cout << "NO SOLUTION";
    else if (n==4) cout << "2 4 1 3";
    else{
        add = n/2;
        if (n%2==1) add++;
        for (int i=1; i<=add; i++){
            cout << i << " ";
            if (i+add <= n) cout << i+add << " ";
        }
    }
    return 0;
}
