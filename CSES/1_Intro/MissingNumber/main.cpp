#include <bits/stdc++.h>

using namespace std;

bool a[200001];
int n,x;

int main()
{
    cin >> n;
    for (int i=0; i<n-1; i++){
        cin >> x;
        a[x] = true;
    }

    for (int i=1; i<=n; i++){
        if (!a[i]){
            cout << i;
        }
    }
    return 0;
}
